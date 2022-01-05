#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"
contact addContact()
{
    contact new;
    printf("AGREGUE EL NUEVO CONTACTO\n");
    fflush(stdin);

    printf("INGRESE: NOMBRE\n");
    gets(new.nameContacto.nombre);
    fflush(stdin);

    printf("INGRESE: APELLIDO\n");
    gets(new.nameContacto.apellido);
    fflush(stdin);

    printf("INGRESE: EDAD\n");
    scanf("%d", &new.edad);

    printf("INGRESE: DNI\n");
    scanf("%d", &new.dni);

    new.estado = 1;

    return new;
}

void dltNmContact(contact schedule[])
{
    int valor = 0;
    int i;
    for (i = 0; i < MAX; i++)
    {
        if (schedule[i].estado == 1)
        {
            valor++;
        }
    }

    if (valor <= 0)
    {
        printf("===========================================================\n");
        printf("LA AGENDA ESTA VACIA\n");
        system("pause");
    }
    else
    {
        system("cls");
        contact nm;
        printf("INGRESE NOMBRE DEL CONTACTO A BORRAR\n");
        fflush(stdin);
        gets(nm.nameContacto.nombre);
        int contadorCoincidencias = 0;
        for (i = 0; i < MAX; i++)
        {
            if (strcmp(strupr(schedule[i].nameContacto.nombre), strupr(nm.nameContacto.nombre)) == 0 && schedule[i].estado == 1)
            {
                contadorCoincidencias++;
            }
        }

        if (contadorCoincidencias > 0)
        {
            printf("ESTAS SON LAS COINCIDENCIAS CON EL NOMBRE\n");
            for (i = 0; i < MAX; i++)
            {
                if (strcmp(strupr(nm.nameContacto.nombre), strupr(schedule[i].nameContacto.nombre)) == 0 && schedule[i].estado == 1)
                {
                    imprimir(schedule[i]);
                }
            }
            printf("===========================================================\n");
            printf("INGRESE NOMBRE DEL CONTACTO A BORRAR\n");
            fflush(stdin);
            gets(nm.nameContacto.nombre);
            printf("INGRESE APELLIDO DEL CONTACTO A BORRAR\n");
            fflush(stdin);
            gets(nm.nameContacto.apellido);

            for (i = 0; i < MAX; i++)
            {
                if (strcmp(strupr(nm.nameContacto.nombre), strupr(schedule[i].nameContacto.nombre)) == 0 &&
                    strcmp(strupr(nm.nameContacto.apellido), strupr(schedule[i].nameContacto.apellido)) == 0)
                {
                    system("cls");
                    printf("===========================================================\n");
                    printf("ESTE CONTACTO SE ELIMINARA\n");
                    imprimir(schedule[i]);
                    schedule[i].estado = 0;
                    schedule[i].dni = 0;
                    schedule[i].edad = 0;
                    strcpy(schedule[i].nameContacto.nombre, "vacio");
                    strcpy(schedule[i].nameContacto.apellido, "vacio");
                    printf("===========================================================\n");
                    printf("EL CONTACTO SE ELIMINO\n");
                    contact aux;
                    for (int i = 0; i < MAX; i++)
                    {
                        for (int j = 0; j < MAX - 1; j++)
                        {
                            int sig = j + 1;
                            if (strcmp(schedule[j].nameContacto.apellido, schedule[sig].nameContacto.apellido) > 0)
                            {
                                aux = schedule[j];
                                schedule[j] = schedule[sig];
                                schedule[sig] = aux;
                            }
                        }
                    }
                }
            }
            system("pause");
        }
        else
        {
            system("cls");
            printf("NO EXISTEN COINCIDENCIAS CON EL NOMBRE\n");
            printf("CONTACTOS ACTUALMENTE EN LA AGENDA\n");
            viewAgenda(schedule);
            system("pause");
        }
    }
}

void imprimir(contact contacto)
{
    printf("===========================================================\n");
    printf("Nombre: %s %s\n", strupr(contacto.nameContacto.apellido), strupr(contacto.nameContacto.nombre));
    printf("Edad: %d\n", contacto.edad);
    printf("DNI: %d\n", contacto.dni);
}

void viewAgenda(contact schedule[])
{
    int valor = 0;
    int i;
    contact aux;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            int sig = j + 1;
            if (strcmp(schedule[j].nameContacto.apellido, schedule[sig].nameContacto.apellido) > 0)
            {
                aux = schedule[j];
                schedule[j] = schedule[sig];
                schedule[sig] = aux;
            }
        }
    }

    for (i = 0; i < MAX; i++)
    {
        if (schedule[i].estado == 1)
        {
            valor++;
        }
    }

    if (valor > 0)

    {
        printf("===========================================================\n");
        printf("CONTACTOS EN LA AGENDA\n");
        for (i = 0; i < MAX; i++)
        {
            if (schedule[i].estado == 1)
            {
                imprimir(schedule[i]);
                printf("ESTADO: 'OCUPADO'\n");
            }
        };
    }
    else
    {
        printf("===========================================================\n");
        printf("LA AGENDA ESTA VACIA\n");
    }
}

void viewGraphic(contact schedule[])
{
    int menores18 = 0;
    int entre19y35 = 0;
    int mayores35 = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (schedule[i].edad > 0 && schedule[i].edad < 19)
        {
            menores18++;
        }
        if (schedule[i].edad > 18 && schedule[i].edad < 36)
        {
            entre19y35++;
        }
        if (schedule[i].edad > 34)
        {
            mayores35++;
        }
    }

    puts("\n==============================\n");

    int mayor = menores18;

    if (entre19y35 > menores18)
    {
        mayor = entre19y35;
    }
    else if (mayores35 > menores18)
    {
        mayor = mayores35;
    }
    int imp = mayor;

    char *matriz[MAX][3];

    for (int i = 0; i < mayor; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = "    ";
        }
    }

    int fila1 = mayor - 1;
    int fila2 = mayor - 1;
    int fila3 = mayor - 1;

    for (int e = 0; e < MAX; e++)
    {
        int edad = schedule[e].edad;
        if (edad > 0 && edad < 18)
        {
            matriz[fila1][0] = " *  ";
            fila1--;
        }
        if (edad >= 18 && schedule[e].edad <= 35)
        {
            matriz[fila2][1] = "  * ";
            fila2--;
        }
        if (edad > 35)
        {
            matriz[fila3][2] = "  * ";
            fila3--;
        }
    }

    for (int i = 0; i < imp; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %s ", matriz[i][j]);
        }
        printf("\n");
    }
    printf(" <18   19-35  >35\n");
    printf("\n");
};
