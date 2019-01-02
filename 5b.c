#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define BUFFER_SIZE 20

int main(int argc,char *argv[])
{
    int rank,size, Destination, i;
    int  root = 3, temp = 1;
    char msg[BUFFER_SIZE];
    
    MPI_Init(&argc,&argv);
    MPI_Status status;
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

   if(rank == 3)        
   {
   // system("hostname");
    strcpy(msg, "Hello ");
    for (temp=0; temp<size;temp++)
    {
    MPI_Send(msg, BUFFER_SIZE, MPI_CHAR, temp, 0,MPI_COMM_WORLD);
    }
     }

else
{          
//system("hostname");
MPI_Recv(msg, BUFFER_SIZE, MPI_CHAR, root, 0,MPI_COMM_WORLD, &status);
printf("\n%s in process with rank %d from Process with rank %d\n", msg,rank,root);
}

 MPI_Finalize();

return 0;

}
