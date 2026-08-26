/*A data muda a cada 12 horas de Sol*/
int contar_horas(int A[], int B[]){

}

int main(void){
    int a1, a2, a3, b1, b2, b3, c1, c2, c3, controle = 0;
    int DATA[300][3], NASCER[300][3], POR[300][3];
    while(scanf("%d/%d/%d %d:%d:%d %d:%d:%d", &a1, &a2, &a3, &b1, &b2, &b3, &c1, &c2, &c3)==9){
        DATA[controle][0] = a1;
        DATA[controle][1] = a2;
        DATA[controle][2] = a3;
        NASCER[controle][0] = b1;
        NASCER[controle][1] = b2;
        NASCER[controle][2] = b3; 
        POR[controle][0] = c1;
        POR[controle][1] = c2;
        POR[controle][2] = c3;   
        controle++;   
    }
}