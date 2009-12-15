/* 
 * File:   main.cpp
 * Author: adrian
 *
 * Created on 12 grudzień 2009, 22:07
 */

/*
 * 
 */
int main(int argc, char** argv) {

    if(argc != 5 || atoi(argv[1]) == 0 || atoi(argv[2]) == 0 || atoi(argv[3]) == 0 || atoi(argv[4]) == 0)
    {
        printerror("Error in worker " + getpid() + ": Invalid program arguments");
        return (EXIT_FAILURE);
    }

    WorkerNode worker(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
    return worker.Run();
}

