#include <stdio.h>
#include <locale.h>

    void verificar_temperatura (float temperatura){
     if (temperatura > 100.0){
        printf("ALERTA: Motor Superaquecido!\n");
    }else{
        printf("Status de Temperatura: OK\n\n");
    }
    }

    void verificar_rotacao (int rotacao){
    if (rotacao > 6500){
        printf("ALERTA: Corte de Giro Acionado!\n\n");
    }else{
        printf("RPM Dentro do Padão\n\n");
    }
    }

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");


    printf("--Sistema de Telemetria Iniciado--\n\n");
    int status_sistema = 1;
    int velocidade = 0;
    int rotacao = 3000;
    int historico_velocidade[5];
    int i;
    int soma_velocidade = 0;
    float media_velocidade = 0.0;
    float temperatura = 90.5;



    while (status_sistema == 1) {

//-------------------------------------------------------------
    printf("Velocidade atual : %d km/h\n", velocidade);
    printf("Rotação atual : %d RPM\n", rotacao);
    printf("Temperatura atual : %.1f C\n\n", temperatura);

//-------------------------------------------------------------
    printf("Nova leitura de velocidade :");
        scanf("%d", &velocidade);
    printf("Registro de velocidade : %d km/h\n\n", velocidade);

//---------------------------------------------------------------
    printf("Nova leitura de Rotação :");
        scanf("%d", &rotacao);
    verificar_rotacao(rotacao);

//-----------------------------------------------------------------
    printf("Nova leitura de Temperatura :");
        scanf("%f", &temperatura);
    verificar_temperatura(temperatura);
//-----------------------------------------------------------------

    printf("\n---- Coleta de Dados ----\n");
        for (i=0; i < 5; i++){
            printf("Digite a Leitura da Velocidade %d: ", i + 1);
                scanf("%d", &historico_velocidade[i]);
        }
    printf("\n---- Coleta Concluida ----\n\n");
//-----------------------------------------------------------------
        soma_velocidade = 0;
        for (i=0; i < 5; i++){
            soma_velocidade = soma_velocidade + historico_velocidade[i];
        }
            media_velocidade = soma_velocidade / 5.0;

        printf("Velocidade Média: %.1f Km/h\n\n", media_velocidade);
//------------------------------------------------------------------
    printf("Nova Leitura ( 1 - Sim / 0 - Desligar Sistema ) : ");
        scanf("%d", &status_sistema);
    printf("---------------------------------------\n\n");


    printf("Sistema Deligado. Fim da Telemetria.\n\n");

//---------------------------------------------------------------------
    }
return 0;
}
