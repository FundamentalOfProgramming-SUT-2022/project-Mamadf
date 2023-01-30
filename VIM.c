#include <stdio.h>
#include<string.h>
#include<stdlib.h>

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
        while(str[i] !=' '){
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
int finding_position(int line, int charc, char tmp[1000]){
    int line_counter = 1;
    int x = 0;
    if(line != 1){
    for(x ;line_counter <= line; x++){
        if(line_counter == line){
            break;
        }
        if(tmp[x] =='\n'){
            line_counter++;
        }
    }
    }
    int y = x+charc+line-1;
    return y;
}

void removestr(char*address, char* tmp, char *bf,int w, int q, int line){
    char tmp2[1000];
    if(strcmp(bf, "-f") == 0){
        int i;
        for(i = 0;i< w-line+1;i++){
        tmp2[i] = tmp[i];
        }
        for(i;i+q<=strlen(tmp);i++){
            if(tmp[i+q] == '\0'){
                tmp2[i] = '\0';
                }
            else
            tmp2[i] = tmp[i+q];
            }
    }
    if(strcmp(bf, "-b")== 0){
        int i;
        for(i = 0;i< w-line+1-q;i++){
            tmp2[i] = tmp[i];
        }
        for(i;i+q<=strlen(tmp);i++){
            if(tmp[i+q] == '\0'){
                tmp2[i] = '\0';
            }
            else
                tmp2[i] = tmp[i+q];
        }
    }
    printf("%s", tmp2);
    FILE * rmv2 = fopen(address, "w");
    fputs(tmp2, rmv2);
    fclose(rmv2);
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
                ins = fopen(address, "r+");
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
                    continue;
                }
                int b, c, o=0;
                char tmp[1000];
                while(fscanf(ins,"%c", &tmp[o]) ==1){
                    o++;
                }
                scanf(" %d:%d", &b, &c);
                int z = strlen(str);
                int l = 1;
                int x=0;
                if(b != 1){
                for( x;l <= b&&tmp[x] != '\0'; x++){
                    if(l == b){
                        break;
                    }
                    if(tmp[x] =='\n'){
                        l++;
                    }
                }
                }
                if(b> l){
                    printf("Wrong position\n");
                    continue;
                }
                else{
                    int y = x+c+b-1;
                    fseek(ins, y, SEEK_SET);
                    fputs(str, ins);
                    rewind(ins);
                    char tmp2[1000];
                    int i = 0;
                    while(i<=y+z-b+1){
                        if(i ==y+z-b+1){
                            tmp2[i] = '\0';
                            break;
                        }
                        else{
                        fscanf(ins, "%c", &tmp2[i]);
                        i++;
                        }
                    }
                    char tmp3[1000];
                    int j;
                    for(j = 0;tmp[y-b+1] != '\0';j++){
                        tmp3[j] = tmp[y-b+1];
                        y++;
                    }
                    if(tmp[y-b+1] == '\0'){
                        tmp3[j] = '\0';
                    }
                    strcat(tmp2, tmp3);
                    FILE *ins2 = fopen(address , "w");
                    fputs(tmp2, ins2);
                    fclose(ins2);
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
            char tmp[1000];
            scanf(" %s", type);
            if(strcmp(type ,  "--file" )== 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            scanf(" %s", position);
            int line, ch;
            int w;
            if(strcmp(position, "--pos") == 0){
                scanf(" %d:%d", &line,&ch);
            }
            else{
                printf("Wrong input\n");
            }
            int o = 0;
            FILE *rmv = fopen(address, "r+");
            while(fscanf(rmv,"%c", &tmp[o]) ==1){
                o++;
            }
            w = finding_position(line, ch, tmp);
            scanf(" %[a-zA-Z- ]", size);
            char r[1000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[1000];
                if(strcmp(bf, "-f") == 0){
                    int i;
                    for(i = 0;i< w-line+1;i++){
                        tmp2[i] = tmp[i];
                    }
                    for(i;i+q<=strlen(tmp);i++){
                        if(tmp[i+q] == '\0'){
                            tmp2[i] = '\0';
                        }
                        else
                        tmp2[i] = tmp[i+q];
                    }
                }
                if(strcmp(bf, "-b")== 0){
                    int i;
                    for(i = 0;i< w-line+1-q;i++){
                        tmp2[i] = tmp[i];
                    }
                    for(i;i+q<=strlen(tmp);i++){
                        if(tmp[i+q] == '\0'){
                            tmp2[i] = '\0';
                        }
                        else
                            tmp2[i] = tmp[i+q];
                        }
                }
                FILE * rmv2 = fopen(address, "w");
                fputs(tmp2, rmv2);
                fclose(rmv2);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
        }
        else if(strcmp(command, "copystr") == 0){
            char tmp[1000];
            scanf(" %s", type);
            if(strcmp(type ,  "--file" )== 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            scanf(" %s", position);
            int line, ch;
            int w;
            if(strcmp(position, "--pos") == 0){
                scanf(" %d:%d", &line,&ch);
            }
            else{
                printf("Wrong input\n");
            }
            int o = 0;
            FILE *cpy = fopen(address, "r+");
            while(fscanf(cpy,"%c", &tmp[o]) ==1){
                o++;
            }
            w = finding_position(line, ch, tmp);
            scanf(" %[a-zA-Z- ]", size);
            char r[1000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[1000];
                if(strcmp(bf,"-f")==0){
                    int i;
                    for(i = 0; i< q;i++){
                        tmp2[i] = tmp[w+i-1];
                    }
                    tmp[i] = '\0';
                }
                if(strcmp(bf,"-b")==0){
                    int i;
                    for( i = 0;i< q;i++){
                        tmp2[i] = tmp[w-q+i-1];
                    }
                    tmp2[i] = '\0';
                }
                FILE * cpy2 = fopen("C:\\Users\\ASUS\\Desktop\\Clip board.txt", "w");
                fputs(tmp2, cpy2);
                fclose(cpy2);
            }
            else{
                printf("Wrong input\n");
            }
        }else if(strcmp(command, "cutstr") == 0){
            char tmp[1000];
            scanf(" %s", type);
            if(strcmp(type ,  "--file" )== 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            scanf(" %s", position);
            int line, ch;
            int w;
            if(strcmp(position, "--pos") == 0){
                scanf(" %d:%d", &line,&ch);
            }
            else{
                printf("Wrong input\n");
            }
            int o = 0;
            FILE *cut = fopen(address, "r+");
            while(fscanf(cut,"%c", &tmp[o]) ==1){
                o++;
            }
            w = finding_position(line, ch, tmp);
            scanf(" %[a-zA-Z- ]", size);
            char r[1000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[1000];
                if(strcmp(bf,"-f")==0){
                    int i;
                    for(i = 0; i< q;i++){
                        tmp2[i] = tmp[w+i-1];
                    }
                    tmp2[i] = '\0';
                }
                if(strcmp(bf,"-b")==0){
                    int i;
                    for( i = 0;i< q;i++){
                        tmp2[i] = tmp[w-q+i-1];
                    }
                    tmp2[i] = '\0';
                }
                removestr(address, tmp, bf, w, q, line);
                FILE * cut2 = fopen("C:\\Users\\ASUS\\Desktop\\Clip board.txt", "w");
                fputs(tmp2, cut2);
                fclose(cut2);
            }
            else{
                printf("Wrong input\n");
            }
        }
        else if(strcmp(command, "pastestr") == 0){
            scanf(" %s", type);
            if(strcmp(type, "--file") == 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
            }
            change_input(address);
            scanf(" %s", position);
            int line, ch;
            if(strcmp(position, "--pos") == 0){
                scanf(" %d:%d", &line, &ch);
            }
            else{
                printf("Wrong input\n");
            }
            FILE* pst;
            if(pst = fopen(address, "r")){
                pst = fopen(address, "r+");
                int o =0;
                char tmp[1000];
                while(fscanf(pst, "%c", &tmp[o]) == 1){
                    o++;
                }
                FILE * pst2 = fopen("C:\\Users\\ASUS\\Desktop\\Clip board.txt", "r");
                int p = 0;
                char tmp2[1000];
                while(fscanf(pst2, "%c", &tmp2[p]) == 1){
                    p++;
                }
                int x = 0;
                int l = 1;
                char *tmp3;
                if(line != 1){
                    for(x;l <= line && tmp[x] != '\0';x++){
                        if(l == line){
                            break;
                        }
                        else{
                            if(tmp[x] == '\n'){
                                l++;
                            }
                            tmp3[x] = tmp[x];
                        }
                    }
                }
                if(line >  l){
                    printf("Wrong position\n");
                }
                else{
                    int i  = 0;
                    for(i;i < ch;i++){
                        tmp3[i+x] = tmp[i+x];
                    }
                    x += i;
                }
                for(int j = 0;j<strlen(tmp2);j++){
                    tmp3[x] = tmp2[j];
                    x++;
                }
                int s = strlen(tmp2);
                for(x;x< s +strlen(tmp);x++){
                    if(tmp[x-s] == '\0'){
                        tmp3[x] == '\0';
                        break;
                    }
                    else{
                        tmp3[x] = tmp[x- s];
                    }
                }
                printf("%s", tmp3);
                FILE * pst3 = fopen(address, "w");
                fputs(tmp3, pst3);
                fclose(pst3);
            }
            else{
                printf("This file doesn't exist\n");
                continue;
            }
        }
        else if(strcmp(command, "find") == 0){
            scanf(" %s", type);
            if(strcmp(type, "--str") == 0){
                scanf(" %[A-Za-z./\\ \"]",str);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_string(str);
            scanf(" %s", type2);
            if(strcmp(type2, "--file") == 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            FILE * fnd;
            if(fnd = fopen(address, "r")){
                fnd = fopen(address, "r");
                char tmp[1000];
                int o = 0;
            }
        }
        else if(command == EOF){
            return 0;
        }

    }
    return 0;
}
