void DodMac(double **mac1, double **mac2, double **mac_out, int n, int m){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            mac_out[i][j] = mac1[i][j] + mac2[i][j];
        }
    }
}
void Mac_x_Wekt(double **mac_in, double *wek_in, double *wek_out, int n, int m){
    int i, j;
    double element;
    for (i = 0; i < n; i++)
    {
        element = 0;
        for (j = 0; j < m; j++)
            element += mac_in[i][j] * wek_in[j];
        wek_out[i] = element;
    }
}
void Mac_x_Mac(double **mac1, double **mac2, double **mac_out, int n, int m, int p){
    //    mac1[n, m] mac2[m, p]
    int i, k, j;
    for (i = 0; i < n; i++){
        for (k = 0; k < m; k++){
            for (j = 0; j < p; j++){
                printf("i=%d k=%d j=%d mac1[ik]=%lf mac2[kj]=%lf\n", i, k, j, mac1[i][k], mac2[k][j]);
                mac_out[i][j] += mac1[i][k] * mac2[k][j];
            }
        }
    }
}