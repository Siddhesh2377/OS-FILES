// IPC using Shared Memory (Writer and Reader in one program)

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    // Step 1: Generate a unique key
    key_t key = ftok("shmfile", 65);

    // Step 2: Create shared memory segment
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Step 3: Attach shared memory segment
    char *str = (char*) shmat(shmid, (void*)0, 0);

    // Step 4: Write data to shared memory
    printf("Write data to shared memory: ");
    fgets(str, 1024, stdin);  // Read string from user input

    printf("Data written in memory: %s\n", str);

    // Step 5: Detach from shared memory
    shmdt(str);

    // Step 6: Attach again to read data
    str = (char*) shmat(shmid, (void*)0, 0);
    printf("Data read from memory: %s\n", str);

    // Step 7: Detach again
    shmdt(str);

    // Step 8: Destroy the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
