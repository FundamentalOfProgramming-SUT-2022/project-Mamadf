#include <stdio.h>
#include<string.h>

void change_input(char *address){
    char address2[1000];
    char path[1000] = "C:\\Users\\ASUS\\Desktop";
    if(address[0]=='"'){
        int i=1;
        int j = 0;
        while(address[i] !='"'){
            if(address[i] == '/'){
                address2[j] = '\\';
                j++;
                address2[j] = '\\';
                j++;
                i++;
            }
            else{
                address2[j] = address[i];
                j++;
                i++;
            }
     }
    address2[j] = '\0';
    strcat(path, address2);
    strcpy(address, path);
    }
    else{
        int i=0;
        int j = 0;
        while(address[i] !='\0'){
            if(address[i] == '/'){
                address2[j] = '\\';
                j++;
                address2[j] = '\\';
                j++;
                i++;
            }
            else{
                address2[j] = address[i];
                j++;
                i++;
            }
     }
     address2[j] = '\0';
     strcat(path, address2);
     strcpy(address, path);
    }
}

void change_string(char *str){
    char str2[1000];
    if(str[0]=='"'){
        int i=1;
        int j = 0;
        while(i < strlen(str)- 2){
            if(str[i] == '\\' && str[i+1] =='n' ){
                strcat(str2, "\n");
                j++;
                i += 2;
            }
            else if(str[i] == '\\' && str[i+1] =='"' ){
                str2[j] = str[i+1];
                j++;
                i += 2;
            }
            else if(str[i] == '\\' && str[i+1] =='\\'){
                str2[j] = str[i];
                i+=2;
                j++;
            }
            else {
                str2[j] = str[i];
                j++;
                i++;
                }
        }
        str2[j] = '\0';
        strcpy(str, str2);
    }
    else{
        int i=0;
        int j = 0;
        while(str[i] !='\0'){
            if(str[i] == '\\' && str[i+1] =='n' ){
                strcat(str2, "\n");
                j++;
                i += 2;
            }
            else if(str[i] == '\\' && str[i+1] =='"' ){
                strcat(str2, "\"");
                j++;
                i += 2;
            }
            else if(str[i] == '\\' && str[i+1] =='\\'){
                str2[j] = str[i];
                j++;
                i+=2;
            }
            else {
                str2[j] = str[i];
                j++;
                i++;
            }
     }
     str2[j] = '\0';
     strcpy(str, str2);
    }
}

int main() {
    while(1){
        char command[1000];
        char type[1000];
        char type2[1000];
        char address[1000];
        char str[1000];
        char position[1000];
        char size[1000];
        scanf("%s", command);
        if(strcmp(command, "createfile") == 0){
            scanf(" %s", type);
            if(strcmp(type,"--file") == 0){
            scanf(" %[^\n]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            FILE *cf;
            if(!(cf = fopen(address, "r"))){
            cf = fopen(address, "w");
            fclose(cf);
            continue;
            }
            else{
                printf("This file already exists\n");
                continue;
            }
        }
        else if(strcmp(command, "insertstr") == 0){
            scanf(" %s", type);
            if(strcmp(type, "--file") == 0){
            scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            FILE *ins;
            if(ins = fopen(address, "r")){
                ins = fopen(address, "a");
                scanf(" %s", type2);
                if(strcmp(type2 , "--str") == 0){
                scanf(" %[A-Za-z./\\ \"]", str);
                }
                else{
                    printf("Wrong input\n");
                    continue;
                }
                change_string(str);
                scanf(" %s", position);
                if(strcmp(position, "--pos") != 0){
                    printf("Wrong input\n");
                }
                int line,pos;
                scanf(" %d:%d", &line,&pos);
                int c_line = 1;
                int c_pos = 0;
                int o = 0;
                char tmp[1000];
                char tmp2[1000];
                int x;
                while(fscanf(ins,"%c", &tmp[o]) ==1){
                    o++;
                }
                while(c_line <=line){
                    for(x = 0;x<strlen(tmp);x++){
                        if(tmp[x] == '\n'){
                            tmp2[x] = tmp[x];
                            c_line++;
                            if(c_line == line){
                                break;
                            }
                        }
                    }
                    break;
                }
                if(c_line == line){
                    for(c_pos;c_pos < pos;c_pos++){
                        tmp2[x] = tmp[x];
                        x++;
                    }
                    int y = x;
                    for(y;y < strlen(str) + x;y++){
                        tmp2[y] = str[y-x];
                    }
                    for(x; x <strlen(tmp);x++){
                        tmp2[y] = tmp[x];
                        y++;
                    }
                    printf("%s", tmp2);
                    fputs(tmp2, ins);
                    fclose(ins);
                }
                else{
                    printf("Wrong position\n");
                }
            }
            else{
                printf("This file doesn't exist\n");
            }
        }
        else if(strcmp(command, "cat") == 0){
            scanf(" %s", type);
            scanf(" %[^\n]", address);
            change_input(address);
            FILE* ct;
            char tmp[1000];
            int j = 0;
            if(ct = fopen(address, "r")){
                while(fscanf(ct,"%c", &tmp[j]) ==1){
                    printf("%c", tmp[j]);
                    j++;
                }
                printf("\n");
            }
            else{
                printf("File doesn't exist\n");
            }
        }
        else if(strcmp(command, "removestr") == 0){
            scanf(" %s", type);
            if(strcmp, "--file" == 0){
                scanf(" %[^\n]", address);
            }
            else{
                printf("Wrong input\n");
                break;
            }
            change_input(address);
            scanf(" %s", position);
            int line, ch;
            if(strcmp(position, "--pos") == 0){
                scanf(" %d:%d", &line,&ch);
            }
            else{
                printf("Wrong input\n");
            }
            scanf(" %s", size);
            int s;
            if(strcmp(size, "-size") == 0){
                scanf(" %d", &s);
            }
            else{
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){

            }
            else{
                printf("Wrong input\n");
            }
        }
        else if(command == EOF){
            return 0;
        }

    }
    return 0;
}
