#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void print_array(int arr[], int size){
	int i;
	for (i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void dsc_sort(int arr[], int size){
	int i,j;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-i-1;j++)
			if(arr[j]<arr[j+1])
				swap(&arr[j],&arr[j+1]);
}

int main(int args, char * argv[]){
	int array[10];
	int num_counter;
	int i = 0 , j = 0;
	char *stringer,temp[20];
	char *holder = temp;
	stringer = argv[2];
	printf("%s\n",stringer);
	while(*(stringer+j) != '\0'){
		if(*(stringer+j)!=','){
			*(holder+i)=*(stringer+j);
			//printf("%c",*(holder+j));
		}
		else{
			sscanf(holder,"%d",&array[num_counter]);
			i=-1;
			num_counter++;
		}
		j++;i++;
	}
	sscanf(holder,"%d",&array[num_counter]);
	num_counter++;
	print_array(array,num_counter);
	dsc_sort(array,num_counter);
	print_array(array,num_counter);
	return 0;
}
