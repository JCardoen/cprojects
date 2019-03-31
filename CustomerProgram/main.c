#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define _POSIX_SOURCE
#include <unistd.h>

int main_exit;

struct client {
    char first_name[20];
    char last_name[20];
    char e_mail[20];
    char phone[20];
    char company[30];
    char vat_no[20];
    char street[20];
    char street_no[8];
    char city[20];
    char zip[10];
    char country[20];
};

void list_clients() {
    get_clients_from_file();
}

void get_clients_from_file() {
    FILE *file_ptr;
    /*file_ptr = fopen("clients.dat", "r");

    // Create dat file if not exist
    if(file_ptr == NULL) {
        file_ptr = fopen("clients.dat", "wb");
    }

    if(!file_ptr) {
        perror("fopen");
    }

    printf("\nCalculating number of clients...");

    // Calculate number of lines
    int total_lines = 0;
    char current_character;
    while(current_character = fgetc(file_ptr)) {
        if(current_character == '\n') {
            total_lines++;
        }
    }

    total_lines++;

    printf("\nTotal number of clients: %i", total_lines);

    fclose(file_ptr);*/

    file_ptr = fopen("clients.dat", "rb");


    // Read each line
    char line[512];
    struct client clients[1];
    char *ch;
    char **line_array = malloc(11);

    while(fgets(line, sizeof line, file_ptr) != NULL) {
        // Split on , delimiter
        ch = strtok(line, ",");
        int iterator = 0;
        while (ch != NULL) {
            line_array[iterator] = ch;
            ch = strtok(NULL, ",");
            iterator++;
        }

        struct client client_to_add;
        strcpy(client_to_add.first_name,line_array[0]);
        strcpy(client_to_add.last_name,line_array[1]);
        strcpy(client_to_add.e_mail,line_array[2]);
        strcpy(client_to_add.phone,line_array[3]);
        strcpy(client_to_add.company,line_array[4]);
        strcpy(client_to_add.vat_no,line_array[5]);
        strcpy(client_to_add.street,line_array[6]);
        strcpy(client_to_add.street_no,line_array[7]);
        strcpy(client_to_add.city,line_array[8]);
        strcpy(client_to_add.zip,line_array[9]);
        strcpy(client_to_add.country,line_array[10]);
        printf("\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLIENT %s %s \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2", client_to_add.first_name, client_to_add.last_name);
        printf("\n\nFirst Name: %s", client_to_add.first_name);
        printf("\n\nLast Name: %s", client_to_add.last_name);
        printf("\n\nE-mail: %s", client_to_add.e_mail);
        printf("\n\nPhone: %s", client_to_add.phone);
        printf("\n\nCompany: %s , VAT: %s", client_to_add.company, client_to_add.vat_no);
        printf("\n\nAddress: %s %s ,%s %s (%s)", client_to_add.street,  client_to_add.street_no, client_to_add.zip, client_to_add.city, client_to_add.country);
        printf("\n\n\n\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 END OF CLIENT SHEET \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        free(line_array);
        line_array = malloc(11);
    }

    fclose(file_ptr);

    check_for_exit:
    printf("\nPress 0 to return to main menu, press 9 to exit.");
    scanf("%d", &main_exit);
    system("cls");

    if(main_exit == 0) {
        system("cls");
        menu();
    } else if (main_exit == 9){
        exit(0);
    } else {
        printf("\nInvalid option!");
        goto check_for_exit;
    }
}


void write_client_to_file(struct client cl) {
    FILE *file_ptr;
    file_ptr = fopen("clients.dat", "a");

    // Create dat file if not exist
    if(file_ptr == NULL) {
        file_ptr = fopen("clients.dat", "wb");
    }

    if(!file_ptr) {
        perror("fopen");
    }

    fprintf(file_ptr, "\n%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s", cl.first_name, cl.last_name, cl.e_mail, cl.phone, cl.company, cl.vat_no, cl.street, cl.street_no, cl.city, cl.zip, cl.country);
    fclose(file_ptr);
}

void create_client() {
    // Create array of pointers that will hold the user input
    struct client cl;
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CREATING NEW CLIENT \xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n Client's first name: ");
    scanf("%s", cl.first_name);

    printf("\n Client's last name: ");
    scanf("%s", cl.last_name);

    printf("\n Client's e-mail: ");
    scanf("%s", cl.e_mail);

    printf("\n Client's phone: ");
    scanf("%s", cl.phone);

    printf("\n Client's company: ");
    scanf("%s", cl.company);

    printf("\n Client's vat no: ");
    scanf("%s", cl.vat_no);

    printf("\n Client's street: ");
    scanf("%s", cl.street);

    printf("\n Client's street no: ");
    scanf("%s", cl.street_no);

    printf("\n Client's city: ");
    scanf("%s", cl.city);

    printf("\n Client's zip: ");
    scanf("%s", cl.zip);

    printf("\n Client's country: ");
    scanf("%s", cl.country);

    check_for_exit:
    printf("\nPress 1 to insert client, press 0 to abort and return to main menu, press 9 to exit.");
    scanf("%d", &main_exit);
    system("cls");

    if(main_exit == 0) {
        menu();
    } else if (main_exit == 1) {
        write_client_to_file(cl);
        menu();
    } else if (main_exit == 9){
        exit(0);
    } else {
        printf("\nInvalid option!");
        goto check_for_exit;
    }
}

void menu(void)
{
    int choice;
    printf("\n\n\n\t\t\t\tDiff Digital");
    printf("\n\n\n\t\t\tClient Management System");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new client\n\t\t2.Update information of existing client\n\t\t4.Check the details of existing client\n\t\t5.Removing existing client\n\t\t6.View all clients\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1: create_client();
        break;
        case 2:
        break;
        case 3:
        break;
        case 4:
        break;
        case 5:
        break;
        case 6: list_clients();
        break;
        case 7: exit(0);
        break;
    }
}

int main()
{
    system("cls");
    system("color 17");
    menu();
    /* Login Details
    printf("\n\n\n\t\tEnter password to login");
    char password[10] = "tstpasswrd";
    char* input = malloc(10);
    scanf("%s", input);

    if(strcmp(input, password) == 0) {
        system("cls");
        menu();
    }*/

    return 0;
}
