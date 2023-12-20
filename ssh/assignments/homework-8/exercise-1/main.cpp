#include <iostream>
#include <TimeSupport.h>
#include <RandomSupport.h>

#include "BinarySearchTree.h"

using namespace std;

// Do not modify the contents of this file

int main(){

    BinarySearchTree tree;

    tree.insert(6);
    tree.insert(3);

        tree.insert(2);
    tree.insert(1);
    tree.insert(8);
      tree.insert(6);
          tree.insert(7);
        tree.insert(8);

    // tree.draw();

    BinarySearchTree backup = tree;
    backup.insert(9);
    backup.insert(10);

    // tree.draw();
    backup.draw();

    backup.remove(backup.search(8));
    
    backup.draw();

      backup.remove(backup.search(6));
    
    backup.draw();

          backup.remove(backup.search(9));
    
    backup.draw();

    //          backup.remove(backup.search(6));
    
    // backup.draw();

                 backup.remove(backup.search(8));
    
    backup.draw();

    // backup.remove(backup.search(7));

    // backup.draw();

    //   backup.remove(backup.search(2));
    //       backup.draw();

        //      backup.remove(backup.search(6));
        //   backup.draw();

        //      backup.remove(backup.search(8));
        //   backup.draw();

    // backup.traverse();

    return 0;
}