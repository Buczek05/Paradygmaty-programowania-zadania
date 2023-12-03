double **DajMac_1(int n, int m){
    double **table;
    table = (double **)malloc(sizeof(double *) * n);
    if (!table){
        error(3, "func: DajMac_1");
    }
    for (int i = 0; i < n; i++){
        table[i] = (double *)malloc(sizeof(double) * m);
        if (!table[i]){
            error(3, "");
        }
    }
    return table;
}
double **DajMac_2(int n, int m){
    double **table, *big_row;
    table = (double **)malloc(sizeof(double *) * n);
    big_row = (double *)malloc(sizeof(double) * n * m);
    if (!table || !big_row){
        error(3, "func: DajMac_2");
    }
    return table;
}
void ZwrocMac_1(double **table, int n){
    if (table){
        for (int i = 0; i < n; i++){
            if (table[i]){
                free(table[i]);
            }
        }
        free(table);
        table = NULL;
    }
}
void ZwrocMac_2(double **table){
    if (table[0]){
        free(table[0]);
        table[0] = NULL;
    }
    if (table){
        free(table);
        table = NULL;
    }
}
void CzytMac(FILE *file, double **table, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (fscanf(file, "%lf", &table[i][j]) != 1) {
                char error_text[256];
                sprintf(error_text, "element nr %d %d", i, j);
                error(5, error_text);
            }
        }
    }
}
void PiszMac(FILE *file, double **table, int n, int m){
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fprintf(file, "%lf ", table[i][j]);
        }
        fprintf(file, "\n");
    }
}