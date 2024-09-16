#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>

int main(int argc, char const *argv[]){
    //controles 
    if(argc!=3) perror("Veuillez saisir un identifient d'exactement 8 caractères et un port!");
    if(strlen(argv[0])!=8) perror("L'identifiant doit être strictement de longeur 8!");

    struct sockaddr_in address;
    address.sin_port=htons(4242);
    inet_aton("127.0.0.1",&address.sin_addr);

    int sock_tcp=socket(PF_INET,SOCK_STREAM,0);
    if(sock_tcp<0) perror("Ouverture de la socket TCP");

    int r=connect(sock_tcp,(struct sockaddr*) &address,sizeof(struct sockaddr_in));

    if(r!=-1){
        int s1=send(sock_tcp,argv[0],8,0);
        int s2=send(sock_tcp,argv[1],strlen(argv[1]),0);
        char rep[100];
        int re1=recv(sock_tcp,&rep,99*sizeof(char),0);
        rep[re1]='\0';
        printf("%s\n",rep);
        int re2=recv(sock_tcp,&rep,99*sizeof(char),0);
        rep[re2]='\0';
        if(s1==-1 || s2==-1 ||re1==-1||re2==-1) perror("Problemes de reception/envoie");
        while(1){
            char buffer[100];
            scanf("%s",buffer);
            int s3=send(sock_tcp,buffer,strlen(buffer),0);
            if(strcmp(buffer,"NEWPL %s %d***")==0 || strcmp(buffer,"REGIS %s %d %d***")==0){
                char ss[100];
                int rr=recv(sock_tcp,ss,99*sizeof(char),0);
                ss[rr]='\0';
                printf("%s\n",ss);
            }else if(strcmp(buffer,"START***")==0){
                //BLoquer tant que la partie ne commence pas
                //place holder
                sleep(100);
            }
            else if(strcmp(buffer,"UNROK***")==0){
                //BLoquer tant que la partie ne commence pas
                //place holder
                char ss[100];
                int rr=recv(sock_tcp,ss,99*sizeof(char),0);
                ss[rr]='\0';
                printf("%s\n",ss);
            }
            else if(strcmp(buffer,"LIST? %d***")==0){
                //BLoquer tant que la partie ne commence pas
                //place holder
                char ss[100];
                int rr=recv(sock_tcp,ss,99*sizeof(char),0);
                ss[rr]='\0';
                printf("%s\n",ss);
            }
            //dans la partie
            else if (strcmp(buffer,"UPMOV %d***")==0 || strcmp(buffer,"DOMOV %d***")==0 || strcmp(buffer,"LEMOV %d***")==0 || strcmp(buffer,"RIMOV %d***")==0){
                char ss[100];
                int rr=recv(sock_tcp,ss,99*sizeof(char),0);
                ss[rr]='\0';
                printf("%s\n",ss);
            }
            

        }

    }else{
        perror("Erreur de connection");
    }


    
    return 0;
}
