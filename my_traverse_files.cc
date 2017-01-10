//
// @file:           my_traverse_files.cc
// @author:         cuckoo
// @date:           2017/01/10 15:20:56
// @description:    Traverse all the files and folders in current directory
// @note:           http://blog.csdn.net/c__allen/article/details/7588446
//                  http://blog.csdn.net/zhuyi2654715/article/details/7605051
//

#include <dirent.h>         // for dirent, DIR
#include <sys/stat.h>       // for stat, lstat(), S_ISDIR()
#include <sys/unistd.h>     // for chdir()
#include <cstring>          // for strcmp()

#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

#include <string>
using std::string;

bool TraverseAllFiles(string path, int & file_nums)
{
    DIR * current_directory = opendir(path.c_str());
    if(!current_directory)
    {
        cerr << "open directory failed!" << endl;
        return false;
    }

    chdir(path.c_str());
    dirent *my_dirent;
    struct stat file_stat;
    while((my_dirent = readdir(current_directory)) != NULL)
    {
        lstat(my_dirent->d_name, &file_stat);
        if(S_ISDIR(file_stat.st_mode))
        {
            if(strcmp(my_dirent->d_name, ".") == 0 ||
                strcmp(my_dirent->d_name, "..") == 0)
                continue;

            cout << "================ BEGIN ================" << endl;
            cout << my_dirent->d_name << endl;
            TraverseAllFiles(my_dirent->d_name, file_nums);
            cout << "================ END ================" << endl;
        }
        else
        {
            cout << my_dirent->d_name << endl;
            ++file_nums;
        }
    }
    chdir("..");
    closedir(current_directory);

    return true;
}

int main(int argc, char const *argv[])
{
    int file_number = 0;
    string dir_path = ".";      // directory to be scanned
    if(argc >= 2)
        dir_path = argv[1];

    cout << "Directory scan of " << dir_path << endl;
    TraverseAllFiles(dir_path, file_number);

    return 0;
}
