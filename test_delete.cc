//
// @file:           test_delete.cc
// @author:         cuckoo
// @date:           2017/01/04 16:25:13
// @description:    what will happen if pointer is deleted for many times?
// @note            set the pointer to nullptr after delete it
//

int main()
{
    int *ip = new int[4]{ 1, 2, 3, 4 };
    delete [] ip;
    // ip = nullptr;
    delete [] ip;

    return 0;
}
