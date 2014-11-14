#include <iostream>
using namespace std;

void Person_Print_void(char *self) {
    cout << *(int *)(self+0) << *(int *)(self+4) << endl;
}

// declare a typedef for a function pointer
typedef void (*fp) (char *);

int main() {

   // Make Virtual Function Table for Person
   char *vft_Person = new char(4);
   *(int *)vft_Person = (int)Person_Print_void;

   // Person P
   char *p = new char(12);
   *(int *)(p+8) = (int)vft_Person;
   // p.age = 300;
   *(int *)(p+0) = 300;
   // p.size = 10;
   *(p+4) = 10;
   // p.Print()
   int *pointer_to_objects_vft_pointer = (int *)(p+8);
   int *vft_pointer = (int *)(*pointer_to_objects_vft_pointer);
   fp function = (fp)(*(vft_pointer+0));
   (function)(p);
}
