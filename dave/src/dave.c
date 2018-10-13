#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sddapi.h"
#include "compiler.h"
#include "getopt.h"
#include "sddapi.h"

// forward references
SddCompilerOptions sdd_getopt(int argc, char **argv);

//void free_fnf(Fnf* fnf);

clock_t c1, c2;

const char* cnfName = "c432.isc.cnf";

void loadSddAndCount() {

    // initialize manager
    SddLiteral var_count1 = 100;     // initial number of variables
    int auto_gc_and_minimize = 0; // disable (0) or enable (1) auto-gc & auto-min
    SddManager *manager1 = sdd_manager_create(var_count1, auto_gc_and_minimize);
    SddNode *sdd1 = sdd_read(
            "/Volumes/repos/r/dev/logic-engine/sdd-utils/sdd-package-2/sdd-2.0/examples/input/opt-swap.sdd",
            manager1);
    SddModelCount count1 = sdd_model_count(sdd1, manager1);
    printf("sdd model count 1: %"PRImcS"\n", count1);
    sdd_manager_free(manager1);

}

void loadCnfCompileToSddCountModels() {

    printf("\nLoading CNF \n");
    Fnf *fnf = read_cnf("/Volumes/repos/r/dev/logic-engine/sdd-utils/sdd-package-2/sdd-2.0/cnf/c432.isc.cnf");
    printf("vars=%"PRIlitS" clauses=%"PRIsS"", fnf->var_count, fnf->litset_count);
    printf("\nCreating VTree \n");

    Vtree *vtree = sdd_vtree_new(fnf->var_count, "balanced");
    printf("\nCreating Manager \n");

    SddManager *manager2 = sdd_manager_new(vtree);

    sdd_vtree_free(vtree);

    SddCompilerOptions options =
            {
                    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, //file names
                    0, //flag
                    "balanced", //vtree type
                    -1, //vtree search mode
                    0, //post-compilation search
                    0 //verbose
            };

    sdd_manager_set_options(&options, manager2);

    printf("\nConverting CNF to SDD.. \n");
    c1 = clock();
    SddNode *sdd2 = fnf_to_sdd(fnf, manager2);
    c2 = clock();
    float secs = (float)(c2-c1)/CLOCKS_PER_SEC;
    printf("\n\nCompilation time: %.3f sec\n",secs);

    printf("\nCounting models.. \n");
    SddModelCount count2 = sdd_model_count(sdd2, manager2);

    printf("sdd model count 2: %"PRImcS"\n", count2);

    printf("Savinf SDD");
    void sdd_save(const char* fname, SddNode *node);
    sdd_save("/Users/dford/Downloads/c432.isc.cnf.sdd",sdd2);

    free_fnf(fnf);
    sdd_manager_free(manager2);


}

int main(int argc, char **argv) {

    loadSddAndCount();
    loadCnfCompileToSddCountModels();
    return 0;
}



