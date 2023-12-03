double *DajWekt(int n){
    return (double*)malloc(n * sizeof(double));
}
void CzytWekt(FILE *file, double *wekt, int n){
    for (int i = 0; i < n; i++) fscanf(file, "%lf", &wekt[i]);
}
void PiszWekt(FILE *file, double *wekt, int n){
    for (int i = 0; i < n; i++) fprintf(file, "%lf ", wekt[i]);
}