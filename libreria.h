#ifndef LIBRERIA_H_INCLUDED
#define LIBRERIA_H_INCLUDED

#define MAX 11

typedef struct nameContacto
{
    char nombre[20];
    char apellido[20];
} name;

typedef struct contacto
{
    name nameContacto;
    int edad;
    int dni;
    int estado;
} contact;

enum opciones
{
    vacio,
    newContact,
    deleteNameContact,
    viewSchedule,
    graphic,
};

contact addContact();
void dltNmContact(contact schedule[]);
void imprimir(contact contacto);
void viewAgenda(contact schedule[]);
void viewGraphic(contact schedule[]);

#endif // LIBRERIA_H_INCLUDED
