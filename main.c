/*
    TRABAJO PRACTICO SOBRE ESTRUCTURAS
    PROFESOR MIGUEL MI�O
    GRUPO: NATALIA DIAZ, BELEN MARTINEZ, BRIAN SARABIA, JUAN CORSO.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int main()
{
    system("cls");
    contact agenda[MAX];
    for (int i = 0; i < MAX; i++)
    {
        agenda[i].edad = 0;
        agenda[i].estado = 0;
    }

    contact primero = {("ricardo"), ("arjona"), 15, 38455245, 1};
    agenda[0] = primero;
    contact segundo = {("lucas"), ("sandoval"), 11, 38455245, 1};
    agenda[1] = segundo;
    contact tercero = {("mirta"), ("legrand"), 9, 38455245, 1};
    agenda[2] = tercero;
    contact cuarto = {("lucia"), ("escobar"), 22, 38455245, 1};
    agenda[3] = cuarto;
    contact quinto = {("lucas"), ("quinto"), 34, 38455245, 1};
    agenda[4] = quinto;
    contact sexto = {("susana"), ("gimenez"), 48, 38455245, 1};
    agenda[5] = sexto;
    contact septimo = {("susana"), ("tapia"), 62, 38455245, 1};
    agenda[6] = septimo;
    contact octavo = {("alfonzo"), ("lopez"), 70, 38455245, 1};
    agenda[7] = octavo;
    contact noveno = {("pipo"), ("chipolati"), 60, 38455245, 1};
    agenda[8] = noveno;

    int ok = 0, i = 9, cantidadDeContactos = 9;
    while (ok < 1)
    {
        if (cantidadDeContactos < MAX)
        {
            int opcion = 0;
            contact nuevo;
            system("cls");
            printf("===========================================================\n");
            printf(" ||| AGENDA DE CONTACTOS ||| \n");
            printf(" |||   QUE DESEA HACER?  |||\n");
            printf("1. INGRESAR NUEVO CONTACTO\n");
            printf("2. BORRAR POR NOMBRE\n");
            printf("3. MOSTRAR AGENDA\n");
            printf("4. MOSTRAR GRAFICO\n");
            printf("5. SALIR \n");
            printf("===========================================================\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case newContact:
                system("cls");
                for (int j = 0; j < MAX; j++)
                {
                    if (agenda[j].estado == 0)
                    {
                        agenda[j] = addContact();
                        break;
                    }
                }
                i++;
                cantidadDeContactos++;
                printf("SU CONTACTO SE HA GUARDADO\n");
                break;

            case deleteNameContact:
                system("cls");
                dltNmContact(agenda);
                if (cantidadDeContactos > 0)
                {
                    cantidadDeContactos--;
                    i--;
                };
                break;

            case viewSchedule:
                system("cls");
                viewAgenda(agenda);
                system("pause");
                break;

            case graphic:
                system("cls");
                viewGraphic(agenda);
                system("pause");
                break;

            default:
                printf("===========================================================\n");
                printf(" USTED A SALIDO DE LA AGENDA \n");
                ok = 2;
                break;
            }
        }else{
            int opcion = 0;
            printf("===========================================================\n");
            printf(" ||| AGENDA DE CONTACTOS ||| \n");
            printf(" |||   QUE DESEA HACER?  |||\n");
            printf("1. LA AGENDA ESTA COMPLETA\n");
            printf("2. BORRAR POR NOMBRE\n");
            printf("3. MOSTRAR AGENDA\n");
            printf("4. MOSTRAR GRAFICO\n");
            printf("5. SALIR \n");
            printf("===========================================================\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case newContact:
                system("cls");
                printf("LA AGENDA ESTA LLENA\n");
            break;

            case deleteNameContact:
                system("cls");
                dltNmContact(agenda);
                if (cantidadDeContactos > 0)
                {
                    cantidadDeContactos--;
                    i--;
                };
                break;

            case viewSchedule:
                system("cls");
                viewAgenda(agenda);
                break;

            case graphic:
                system("cls");
                viewGraphic(agenda);
                break;

            default:
                printf("===========================================================\n");
                printf(" USTED A SALIDO DE LA AGENDA \n");
                ok = 2;
                break;
            }
        }
    }
    printf("SE COMPLETO LA AGENDA O SALIO DEL PROGRAMA\n");
};