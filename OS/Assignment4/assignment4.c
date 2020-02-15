#include<stdio.h>
#include<stdlib.h>
typedef struct Process {
        char process[10];
        int at;
        int bt;
        int killed;
}Pr;

void swap(Pr *xp, Pr *yp)
{
        Pr temp = *xp;
        *xp = *yp;
        *yp = temp;
}

int atbubbleSort(Pr arr[], int n)
{
        int i, j;
        for (i = 0; i < n-1; i++)
                for (j = 0; j < n-i-1; j++)
                        if (arr[j].at > arr[j+1].at)
                                swap(&arr[j], &arr[j+1]);
      return arr[i].at;
}

int main(){
        int size,i,max,j,k,ts,killcount,time;
        printf("enter number of processes: ");
        scanf("%d",&size);
        killcount = size;
        Pr* pr = (Pr*)malloc(size*sizeof(Pr));
        for(i=0;i<size;i++){
                printf("Process name: ");
                scanf("%s",pr[i].process);
                printf("Arrival Time: ");
                scanf("%d",&pr[i].at);
                printf("Burst Time: ");
                scanf("%d",&pr[i].bt);
                pr[i].killed = 0;
        }
        //menu:
        printf("choose algotithm: \n1> FCFS\n2> SJF\n3> RR\n: ");
        scanf("%d",&i);
        switch(i){
                case 1:
                        atbubbleSort(pr,size);
                        printf("process sequence: ");
                        for(i=0;i<size;i++){
                                printf("%s\t",pr[i].process);
                        }
                        printf("\n");
                        break;
                case 2:
                        max = atbubbleSort(pr,size);
                        for(i=0;i<max;i++){
                                for(j=0;j<size;j++){
                                        for(k=0;k<size-j-1;k++){
                                                if(pr[k].at==i&&pr[k+1].at==i){
                                                        if(pr[k].bt>pr[k+1].bt){
                                                                swap(&pr[k],&pr[k+1]);
                                                        }
                                                }
                                        }
                                }
                        }
                        for(i=0;i<size;i++){
                                printf("%s\t",pr[i].process);
                        }
                        printf("\n");
                        break;
                case 3:
                        time = 0;
                        printf("enter timeslice: ");
                        scanf("%d",&ts);
                        printf("execution sequence:\nPrc\ttime\n");
                        for(i=0;killcount != 0;i=(++i)%size){
                                time++;
                                if(pr[i].killed != 1 && pr[i].at<=time){
                                        pr[i].bt = pr[i].bt - ts;
                                        printf("%s\t%dus\n",pr[i].process,time);
                                        time+=ts;
                                        if(pr[i].bt<=0){
                                                pr[i].killed = 1;
                                                killcount--;
                                        }
                                }
                        }
                        printf("\n");
                        break;
                default:
                        printf("invalid choice\n");
        }
        return 0;
}
