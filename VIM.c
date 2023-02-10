#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void change_input(char *address){
    char address2[10000];
    char path[10000] = "C:\\Users\\ASUS\\Desktop";
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
void change_input2(char *address){
    char address2[10000];
    char path[10000] = "C:\\Users\\ASUS\\Desktop\\Root1";
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
    char str2[10000];
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
            else if(str[i] == '\\' && str[i+1] =='*' ){
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
            else if(str[i] == '\\' && str[i+1] =='*' ){
                str2[j] = str[i+1];
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
int finding_position(int line, int charc, char tmp[10000]){
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
    char tmp2[10000];
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
char * newstr( char *s, size_t n ){
    char *src = s;
    while ( *src && n ) --n, ++src;
    if ( n == 0 && src != s )
    {
        for ( char *dst = s; (  *dst++ = *src++ ); );
    }
    return s;
}
int byword(int inp, char *tmp){
    int word = 1;
    for(int i = 0;i <= inp;i++){
        if(tmp[i] == '\n' ||tmp[i] == ' '){
            word++;
        }
    }
    return word;
}

int main() {
    char command[10000];
    while(scanf("%s", command) != EOF){
        char type[10000];
        char type2[10000];
        char address[10000];
        char str[10000];
        char position[10000];
        char size[10000];
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
            char und[10000];
            int un = 0;
            FILE *undo = fopen(address, "r");
            while(fscanf(undo, "%c", &und[un]) == 1){
                un++;
            }
            newstr(address, 21);
            change_input2(address);
            FILE* undo2 = fopen(address, "w");
            fputs(und, undo2);
            fclose(undo2);
            newstr(address, 27);
            change_input(address);
            FILE *ins;
            if(ins = fopen(address, "r")){
                ins = fopen(address, "r+");
                scanf(" %s", type2);
                if(strcmp(type2 , "--str") == 0){
                scanf(" %[A-Za-z./\\ \"*]", str);
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
                char tmp[10000];
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
                    char tmp2[10000];
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
                    char tmp3[10000];
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
            char tmp[10000];
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
            char tmp[10000];
            scanf(" %s", type);
            if(strcmp(type ,  "--file" )== 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            char und[10000];
            int un = 0;
            FILE *undo = fopen(address, "r");
            while(fscanf(undo, "%c", &und[un]) == 1){
                un++;
            }
            newstr(address, 21);
            change_input2(address);
            FILE* undo2 = fopen(address, "w");
            fputs(und, undo2);
            fclose(undo2);
            newstr(address, 27);
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
            char r[10000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[10000];
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
            char tmp[10000];
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
            char r[10000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[10000];
                if(strcmp(bf,"-f")==0){
                    int i;
                    for(i = 0; i< q;i++){
                        tmp2[i] = tmp[w+i];
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
            char tmp[10000];
            scanf(" %s", type);
            if(strcmp(type ,  "--file" )== 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input(address);
            char und[10000];
            int un = 0;
            FILE *undo = fopen(address, "r");
            while(fscanf(undo, "%c", &und[un]) == 1){
                un++;
            }
            newstr(address, 21);
            change_input2(address);
            FILE* undo2 = fopen(address, "w");
            fputs(und, undo2);
            fclose(undo2);
            newstr(address, 27);
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
            char r[10000];
            scanf("%s", r);
            if(strcmp(size, "-size ") != 0){
                printf("Wrong input\n");
            }
            char bf[2];
            scanf(" %s", bf);
            int q= atoi(r);
            if((strcmp(bf,"-f")==0) || (strcmp(bf,"-b")==0)){
                char tmp2[10000];
                if(strcmp(bf,"-f")==0){
                    int i;
                    for(i = 0; i< q;i++){
                        tmp2[i] = tmp[w+i];
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
            char und[10000];
            int un = 0;
            FILE *undo = fopen(address, "r");
            while(fscanf(undo, "%c", &und[un]) == 1){
                un++;
            }
            newstr(address, 21);
            change_input2(address);
            FILE* undo2 = fopen(address, "w");
            fputs(und, undo2);
            fclose(undo2);
            newstr(address, 27);
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
                char tmp[10000];
                while(fscanf(pst, "%c", &tmp[o]) == 1){
                    o++;
                }
                FILE * pst2 = fopen("C:\\Users\\ASUS\\Desktop\\Clip board.txt", "r");
                int p = 0;
                char tmp2[10000];
                while(fscanf(pst2, "%c", &tmp2[p]) == 1){
                    p++;
                }
                int x = 0;
                int l = 1;
                char *tmp3;
                tmp3 = malloc(10000*sizeof(char));
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
                scanf(" %[A-Za-z./\\ \"*]",str);
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
            char tmp[10000];
            int o = 0;
            while(fscanf(fnd, "%c", &tmp[o]) == 1){
                o++;
            }
            tmp[o] = '\0';
            int size = strlen(tmp);
            int j;
            int count = 0;
            int a[20];
            int len = 0;
            char * res;
            if(str[0] == '*'){
                newstr(str, 1);
                str[strlen(str)] = '\0';
                while(1){
                    res = strstr(tmp, str);
                    for(j = res-tmp;j>= 0;j--){
                        if(tmp[j] == ' ' || tmp[j] == '\n'){
                            a[count] = j + len + 1;
                            break;
                        }
                        if(j == 0){
                            if(count == 0){
                                a[count] = 0;
                                break;
                            }
                            else{
                                a[count] = a[count-1];
                                break;
                            }
                        }
                    }
                    int b = strlen(tmp);
                    int c = res-tmp+strlen(str);
                    if(c <=0){
                        break;
                    }
                    else{
                    len += c;
                    newstr(tmp, c);
                    tmp[b - c] = '\0';
                    count++;
                    }
                }
            }
            else{
                int star_counter = 0;
                int star_counter2 = 0;
                int p;
                FILE * fnd3;
                fnd3 = fopen("C:\\Users\\ASUS\\Desktop\\str ing.txt", "w");
                fputs(str, fnd3);
                char str2[10000];
                char str3[10000];
                int o1 = 0;
                int o2 = 0;
                while(fscanf(fnd3, "%c", &str2[o1]) == 1){
                    o1++;
                }
                while(fscanf(fnd3, "%c", &str3[o2]) == 1){
                    o2++;
                }
                for(p = 0; str[p] != '\0';p++){
                    if(str[p] == ' ' && str[p+1] == '*'){
                        str[p] = '\0';
                    }
                    if(str[p] =='*' && str[p+1] == ' '){
                        str[p] = '\0';
                    }
                }
                if(str[strlen(str)-1] == '*'){
                    str[strlen(str)-1] = '\0';
                    int x = 0;
                    while(x< size){
                        res = strstr(tmp, str);
                        a[count] = res - tmp + len;
                        int s;
                        if(res-tmp+len < 0){
                            break;
                        }
                        for(s = res- tmp;;s++){
                            if(tmp[s] == ' '||tmp[s] == '\n'){
                                break;
                            }
                        }
                        int b = strlen(tmp);
                            x = res - tmp+len;
                            if(x > size){
                                break;
                            }
                            len += s;
                            newstr(tmp, s);
                            tmp[b - s] = '\0';
                            count++;

                    }
                }
                else{
                    int x = 0;
                    while(x< size){
                        res = strstr(tmp, str);
                        a[count] = res - tmp + len;
                        int b = strlen(tmp);
                        int f = strlen(str);
                            x = res - tmp+len;
                            if(x > size){
                                break;
                            }
                            int s = res - tmp;
                         //   printf("%d", s);
                            if(s < 0){
                                break;
                            }
                            len += res -tmp+f;
                            newstr(tmp, res-tmp+f);
                            tmp[b - s] = '\0';
                            count++;
                    }
                }
            }
            char output[10000];
            scanf(" %[^\n]", output);
            FILE *fnd2 = fopen(address, "r");
            char byd[10000];
            int g = 0;
            while(fscanf(fnd2, "%c", &byd[g]) == 1){
                g++;
            }
            byd[g] = '\0';
            if(strcmp(output, "-count") == 0){
                printf("%d\n", count);
            }
            else if(strcmp(output, "-all") == 0){
                for(int k = 0;k < count;k++){
                    printf("%d ", a[k]);
                }
                printf("\n");
            }
            else if(strcmp(output, "-all -byword") == 0 ||strcmp(output, "-byword -all") == 0){
                for(int k = 0;k< count;k++){
                    int bwd = byword(a[k], byd);
                    printf("%d ", bwd);
                }
                printf("\n");
            }
            else if(output[0] == '-' && output[1] == 'a'&& output[2] == 't' && strlen(output) == 5){
                int r = output[4] - '0';
                if(r > count){
                    printf("-1\n");
                }
                else{
                    printf("%d\n", a[r-1]);
                }
            }
            else if(output[2] == 't' && strlen(output) == 13){
                int r = output[4] - '0';
                if(r > count){
                    printf("-1\n");
                }
                else{
                    int wrd = byword(a[r-1], byd);
                    printf("%d\n", wrd);
                }
            }
            else if(output[10] == 't' && strlen(output) == 13){
                int r = output[12] - '0';
                if(r > count){
                    printf("-1\n");
                }
                else{
                    int wrd = byword(a[r-1], byd);
                    printf("%d\n", wrd);
                }
            }
            else if(strcmp(output, "-byword") == 0){
                int r = byword(a[0], byd);
                printf("%d\n", r);
            }
            else if(strcmp(output, "-ans") == 0){
                printf("%d\n", a[0]);
            }
            else{
                printf("Wrong input\n");
            }
            }
        }
        else if(strcmp(command, "grep") == 0){
            scanf(" %s", type);
            if(strcmp(type , "--str") == 0){
                scanf(" %[A-Za-z./\\ \"*]", str);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_string(str);
            int i = 0;
            scanf(" %s ", type2);
            char adrs[100][100];
            if(strcmp(type2, "--file") == 0){
                while(1){
                    for(int j = 0;;j++){
                        scanf("%c", &adrs[i][j]);
                        if(adrs[i][j] == ' '){
                            adrs[i][j] = '\0';
                            i++;
                            break;
                        }
                        if(adrs[i][j] == '\n' || adrs[i][j] == '-'){
                            adrs[i][j] = '\0';
                            goto label_name;
                        }
                    }
                }
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            label_name :
            for(int k = 0;k<= i;k++){
                char *cng = adrs[k];
                change_input(cng);
            }
            char option;
            scanf(" %c", &option);
            char output[100][100];
            char output2[100][100];
            int s = 0;
            int k = 0;
            while(k<i){
                FILE* grp = fopen(adrs[s], "r");
                int o = 0;
                char tmp[10000];
                while(fscanf(grp, "%c", &tmp[o]) == 1){
                    o++;
                }
                for(int p = 0;adrs[s][p] != '\0';p++){
                    output[k][p] = adrs[s][29+p];
                }
                while(1){
                    char *res = strstr(tmp, str);
                    for(int j = res -tmp;j >= 0;j--){
                        if(tmp[j] == '\n'){
                            newstr(tmp, j);
                            for(int  x = 0; tmp[x] ='\0';x++){
                                if(tmp[x] == '\n'){
                                    strcpy(output2[k], tmp);
                                    output2[k][x] = '\0';
                                    newstr(tmp, x);
                                    break;
                                }
                            }
                            break;
                        }
                        if(j == 0){
                            for(int  x = 0; tmp[x] ='\0';x++){
                                if(tmp[x] = '\n'){
                                    strcpy(output2[k], tmp);
                                    output2[k][x] = '\0';
                                    newstr(tmp, x);
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    printf("%s", output2[0]);
                    char * res2 = strstr(tmp, str);
                    k++;
                    if(res2 == 0){
                        s++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            if(option == 'c'){
                printf("%d\n", s+1);
            }
            else if(option == 'l'){
                for(int z= 0;z<= s;z++){
                    if(output[z]  == output[z+1]){
                        z++;
                    }
                    printf("%s\n", output[z]);
                }
            }
            else if(option == 'r'){
                for(int z = 0; z<= s;z++){
                    printf("%s: %s", output[z], output2[z]);
                }
            }
        }
        else if(strcmp(command, "undo") == 0){
            scanf(" %s", type);
            if(strcmp(type,"--file") == 0){
                scanf(" %[A-Za-z./ \"]", address);
            }
            else{
                printf("Wrong input\n");
                continue;
            }
            change_input2(address);
            FILE * und = fopen(address, "r");
            char tmp[10000];
            int o = 0;
            while(fscanf(und, "%c", &tmp[o]) == 1){
                o++;
            }
            newstr(address, 27);
            change_input(address);
            FILE * und2 = fopen(address, "w");
            fputs(tmp, und2);
            fclose(und2);
        }
    }
    return 0;
}
