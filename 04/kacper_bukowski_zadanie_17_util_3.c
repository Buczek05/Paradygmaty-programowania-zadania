void DodWekt(double *wekt1, double *wekt2, double *wekt_out, int n){
    for (int i = 0; i < n; i++){
        wekt_out[i] = wekt1[i] + wekt2[i];
    }
}
double IloczynSkal(double *wekt1,double *wekt2,int n){
    double iloczyn_skal = 0;
    for (int i = 0; i < n; i++){
        iloczyn_skal += wekt1[i] * wekt2[i];
    }
    return iloczyn_skal;
}
double MaxElem(double *wekt, int n){
    double max_element = 0;
    for (int i = 0; i < n; i++){
        max_element = wekt[i] > max_element ? wekt[i] : max_element;
    }
    return max_element;
}