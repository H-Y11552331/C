//
//  main.c
//  shell
//
//  Created by 山元陽佑雅 on 2020/09/23.
//
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LEN 200
#define MAX_ARGS 50

typedef struct _pid{
    int id;
    struct _pid *next;
}Pid;

int fg;

void deletepid(Pid *head,int pid);
void printpid(Pid *head);
void killfg(int sig);
void printepid(int sig);

void deletepid(Pid *head,int pid){
    Pid *x = head;
    Pid *temp;
    while(x != NULL){
        if(x->next ==NULL){
            break;
        }
        if(x->next->id == pid){
            temp = x->next;
            x->next = temp->next;
        }
        x = x->next;
    }
}

void printpid(Pid *head){
    Pid *x = head->next;
    if(head->next != NULL){
        printf("実行中のプロセスは\n");
        while(x != NULL){
            printf("PID %d\n",x->id);
            x = x->next;
        }
        puts("です。");
    }else{
        puts("実行中のプロセスはありません。");
    }
}

void killfg(int sig){
    if(fg != 0){
        kill(fg,SIGINT);
    }
    printf("\n");
}

void printepid(int sig){
    int bg1,status;
    while((bg1 = waitpid(-1,&status,WNOHANG)) > 0){
        printf("PID %dは終了しました。\n",bg1);
    }
}

int main(void) {
    Pid *PID = malloc(sizeof(Pid));
    PID->id = 0;
    PID->next = NULL;
    Pid *head = PID;

    int pid,status,n = 0,i = 0,j,bg1,and,sura;

    char input[MAX_LEN],*parge[MAX_ARGS],*cp,*val,env[600],*new1[MAX_ARGS],new2[MAX_ARGS][MAX_LEN],s[2] = {'/'};

    struct stat sb;

    signal(SIGINT,killfg);

    signal(SIGCHLD,printepid);

    while(1){

        memset(input,'\0',MAX_LEN);

        n++;

        sura = 0;

        while((bg1 = waitpid(-1,&status,WNOHANG)) > 0){
            if(WIFEXITED(status)){
                deletepid(head,pid);
            }
        }

        printf("[command%d] ",n);

        fgets(input,sizeof(input),stdin);

        i = 0;

        while(input[i]){
            if(input[i] == '\n'){
                input[i] = '\0';
            }
            i++;
        }

        cp = input;

        j = 0;

        for(i = 0;i < MAX_ARGS;i++){
            if((parge[i] = strtok(cp," \t")) == NULL){
                break;
            }
            j++;
            cp = NULL;
        }

        if(parge[0] == NULL){
            continue;
        }

        and = 0;

        i = 0;

        while(parge[j-1][i]){
            if(parge[j-1][i]  == '&'){
                and = 1;
                parge[j-1][i] = '\0';
            }
            i++;
        }

        if(strcmp(parge[0],"exit") == 0 || strcmp(parge[0],"quit") == 0){
            break;
        }

        if(strcmp(parge[0],"jobs") == 0){
            printpid(head);
            continue;
        }

        if(strcmp(parge[0],"fg") == 0){
            fg = atoi(parge[1]);
            waitpid(fg,&status,0);
            deletepid(head,fg);
            fg = 0;
            continue;
        }

        for(i = 0;i < strlen(parge[0]);i++){
            if(parge[0][i] == '/'){
                sura++;
            }
        }

        if(sura == 0){
            val = getenv("PATH");
            strncpy(env,val,strlen(val));
            cp = env;
            for(i = 0;i < MAX_ARGS;i++){
                if((new1[i] = strtok(cp,":")) == NULL){
                    break;
                }
                cp = NULL;
            }

            for(i = 0;i < MAX_ARGS;i++){
                if(new1[i] == NULL){
                    break;
                }
                strncpy(new2[i],new1[i],strlen(new1[i]));
                strcat(new2[i],s);
                strcat(new2[i],parge[0]);
                stat(new2[i],&sb);
                if(S_ISREG(sb.st_mode) & S_IXUSR){
                    //printf("%s:%d:%d\n",new2[i],S_IXOTH,S_ISREG(sb.st_mode));
                    strcpy(parge[0],new2[i]);
                }else{
                    memset(new2[i],'\0',strlen(new2[i]));
                }
            }
            //puts("e");
        }

        for(i = 0;i < MAX_ARGS;i++){
            //printf("%s\n",new2[i]);
        }

        pid = fork();

        if(pid == -1){
            puts("子プロセスを生成できませんでした。");//失敗
            exit(-1);
        }else if(pid == 0){
            if(sura == 0){
                for(i = 0;i < MAX_ARGS;i++){
                    stat(new2[i],&sb);
                    if(S_ISREG(sb.st_mode) & S_IXUSR){
                        //printf("%s:%d:%d\n",new2[i],S_IXOTH,S_ISREG(sb.st_mode));
                        strcpy(parge[0],new2[i]);
                    }else{
                        memset(new2[i],'\0',strlen(new2[i]));
                    }
                    //printf("%s\n",new2[i]);
                }
            }
            //printf("%s\n",parge[0]);
            execv(parge[0],parge);
            exit(-1);
        }else if(and == 0){
            fg = pid;
            waitpid(pid,&status,0);
            fg = 0;
        }else if(and == 1){
            Pid *temp = malloc(sizeof(Pid));
            temp->id = pid;
            while(PID->next != NULL){
                PID = PID->next;
            }
            PID->next = temp;
            temp->next = NULL;
        }
    }
    return EXIT_SUCCESS;
}

//shell-f
*/
/*
  ============================================================================
  Name        : shell-f.c
  Author      :
  Version     :
  Copyright   : Your copyright notice
  Description : Hello World in C, Ansi-style
  ============================================================================
*/

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <signal.h>
 #include <sys/stat.h>
 #include <sys/types.h>

 #define MAX_LEN 200
 #define MAX_ARGS 50

 typedef struct _pid{
     int id;
     struct _pid *next;
 }Pid;

 int fg;

 int n = 0;

 void deletepid(Pid *head,int pid);
 void printpid(Pid *head);
 void killfg(int sig);
 void printepid(int sig);

 void deletepid(Pid *head,int pid){
     Pid *x = head;
     Pid *temp;
     while(x != NULL){
         if(x->next ==NULL){
             break;
         }
         if(x->next->id == pid){
             temp = x->next;
             x->next = temp->next;
         }
         x = x->next;
     }
 }

 void printpid(Pid *head){
     Pid *x = head->next;
     if(head->next != NULL){
         printf("実行中のプロセスは\n");
         while(x != NULL){
             printf("PID %d\n",x->id);
             x = x->next;
         }
         puts("です。");
     }else{
         puts("実行中のプロセスはありません。");
     }
 }

 void killfg(int sig){
     if(fg != 0){
         kill(fg,SIGINT);
         printf("\n");
     }else{
         n++;
         printf("\n[command%d] ",n);
         fflush(stdout);
     }
 }

 void printepid(int sig){
     int bg1,status;
     while((bg1 = waitpid(-1,&status,WNOHANG)) > 0){
         printf("PID %dは終了しました。\n",bg1);
     }
 }

 int main(void) {
     Pid *PID = malloc(sizeof(Pid));
     PID->id = 0;
     PID->next = NULL;
     Pid *head = PID;

     int pid,status,i = 0,j,bg1,and,sura;

     char input[MAX_LEN],*parge[MAX_ARGS],*cp,*val,env[600],*new1[MAX_ARGS],new2[MAX_ARGS][MAX_LEN],s[2] = {'/'};

     for(i = 0;i < MAX_ARGS;i++){
         memset(new2[i],'\0',MAX_LEN);
     }

     signal(SIGINT,killfg);

     signal(SIGCHLD,printepid);

     while(1){

         memset(input,'\0',MAX_LEN);

         for(i = 0;i < MAX_ARGS;i++){
             memset(new2[i],'\0',MAX_LEN);
         }

         n++;

         sura = 0;

         while((bg1 = waitpid(-1,&status,WNOHANG)) > 0){
             if(WIFEXITED(status)){
                 deletepid(head,pid);
             }
         }

         printf("[command%d] ",n);

         fgets(input,sizeof(input),stdin);

         i = 0;

         while(input[i]){
             if(input[i] == '\n'){
                 input[i] = '\0';
             }
             i++;
         }

         cp = input;

         j = 0;

         for(i = 0;i < MAX_ARGS;i++){
             if((parge[i] = strtok(cp," \t")) == NULL){
                 break;
             }
             j++;
             cp = NULL;
         }

         if(parge[0] == NULL){
             continue;
         }

         and = 0;

         i = 0;

         while(parge[j-1][i]){
             if(parge[j-1][i]  == '&'){
                 and = 1;
                 parge[j-1][i] = '\0';
             }
             i++;
         }

         if(strcmp(parge[0],"exit") == 0 || strcmp(parge[0],"puit") == 0){
             break;
         }

         if(strcmp(parge[0],"jobs") == 0){
             printpid(head);
             continue;
         }

         if(strcmp(parge[0],"fg") == 0){
             fg = atoi(parge[1]);
             waitpid(fg,&status,0);
             deletepid(head,fg);
             fg = 0;
             continue;
         }

         if(parge[0][0] == '/'){
             sura++;
         }

         if(sura == 0){
             val = getenv("PATH");
             strncpy(env,val,strlen(val));
             cp = env;
             for(i = 0;i < MAX_ARGS;i++){
                 if((new1[i] = strtok(cp,":")) == NULL){
                     break;
                 }
                 cp = NULL;
             }

             for(i = 0;i < MAX_ARGS;i++){
                 if(new1[i] == NULL){
                     break;
                 }
                 strncpy(new2[i],new1[i],strlen(new1[i]));
                 strcat(new2[i],s);
                 strcat(new2[i],parge[0]);
             }
         }

         pid = fork();

         if(pid == -1){
             puts("子プロセスを生成できませんでした。");//失敗
             exit(-1);
         }else if(pid == 0){
             if(sura == 0){
                 i = 0;
                 while(new2[i]){
                     strncpy(parge[0],new2[i],MAX_LEN);
                     execv(parge[0],parge);
                     i++;
                 }
             }else{
                 execv(parge[0],parge);
             }
             exit(-1);
         }else if(and == 0){
             fg = pid;
             waitpid(pid,&status,0);
             fg = 0;
         }else if(and == 1){
             Pid *temp = malloc(sizeof(Pid));
             temp->id = pid;
             while(PID->next != NULL){
                 PID = PID->next;
             }
             PID->next = temp;
             temp->next = NULL;
         }
     }
     return EXIT_SUCCESS;
 }

