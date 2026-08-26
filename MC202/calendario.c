/*A data muda a cada 12 horas de Sol*/
int contar_horas(int A[a][], int B[b][]){
    int segundos, minutos, horas, dias;
    segundos = (A[a][2]+B[b][2]);
    minutos = (A[a][1]+B[b][1]+(segundos/60));
    segundos = segundos%60;
    horas = (A[a][0]+B[b][0]+(minutos/60));
    minutos = minutos%60;
    dias = horas/24;
    horas = horas%24;
    return segundos, minutos, horas, dias;
}

int main(void){
    int a1, a2, a3, b1, b2, b3, c1, c2, c3, controle = 0;
    int DATA[300][3], NASCER[300][3], POR[300][3];
    int dias_passados;
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
    for(int i=0; i<=controle; i++){
        
    }
}