#include <bits/stdc++.h>
// 101 problem
using namespace std;

typedef struct coordinate {
    int row, col;
};

void printArray(int arr[][25], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

coordinate search(int arr[][25], int key, int size) {
    coordinate location;
    location.row = -1;
    location.col = -1;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == key) {
                location.row = i;
                location.col = j;
                return location;
            }
        }
    }

    return location; // not found;
}


int main()
{
    coordinate locationA, locationB;
    string command, place;
    int numBlocks, a, b, temp;
    cin >> numBlocks;

    int blocks[25][25];

    // setup the blocks first
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < numBlocks; j++) {
            blocks[i][j] = -1;  // flag
        }
    }


    // set up initial config
    for (int i = 0; i < numBlocks; i++) {
        blocks[0][i] = i;
    }


    while (cin >> command, command != "quit") {
        cin >> a >> place >> b;

        if (a == b) continue;   // illegal command

        locationA = search(blocks, a, numBlocks);   // search for a
        locationB = search(blocks, b, numBlocks);   // search for b

        if (locationA.col == locationB.col) continue;  // illegal
        if (locationA.col == -1 || locationA.row == -1
            || locationB.row == -1 || locationB.col == -1)   continue; // illegal

        // move case
        if (command == "move") {
            if (place == "onto") {

                // clear top of a (except a)
                for (int i = locationA.row+1; i < numBlocks; i++) {
                    if (blocks[i][locationA.col] == -1) break;

                    temp = blocks[i][locationA.col];
                    blocks[0][temp] = temp;
                    blocks[i][locationA.col] = -1; // reset

                }

                // clear top of b (except b)
                for (int i = locationB.row+1; i < numBlocks; i++) {
                    if (blocks[i][locationB.col] == -1) break;

                    temp = blocks[i][locationB.col];
                    blocks[0][temp] = temp;
                    blocks[i][locationB.col] = -1; // reset

                }

                // moves a to b
                temp = blocks[locationA.row][locationA.col];
                blocks[locationB.row+1][locationB.col] = temp;
                blocks[locationA.row][locationA.col] = -1;  // reset

            } else if (place == "over") {

               // clear top of a (except a)
                for (int i = locationA.row+1; i < numBlocks; i++) {
                    if (blocks[i][locationA.col] == -1) break;

                    temp = blocks[i][locationA.col];
                    blocks[0][temp] = temp;
                    blocks[i][locationA.col] = -1; // reset

                }

                // put a on top of stack b
                for (int i = locationB.row+1; i < numBlocks; i++) {
                    if (blocks[i][locationB.col] == -1) {   // first empty spot
                        blocks[i][locationB.col] = blocks[locationA.row][locationA.col];   // setting a
                        blocks[locationA.row][locationA.col] = -1;  // reset
                        break;
                    }
                }
            }
        } else if (command == "pile") { // pile case
            if (place == "onto") {
                // clear top of b (except b)
                for (int i = locationB.row+1; i < numBlocks; i++) {
                    if (blocks[i][locationB.col] == -1) break;

                    temp = blocks[i][locationB.col];
                    blocks[0][temp] = temp;
                    blocks[i][locationB.col] = -1; // reset

                }

                int rowB = locationB.row+1; // prev error

                // copy stack a on top of b
                for (int i = locationA.row; i < numBlocks; i++) {
                    if (blocks[i][locationA.col] == -1) break;

                    blocks[rowB][locationB.col] = blocks[i][locationA.col];
                    blocks[i][locationA.col] = -1;
                    rowB++;
                }


            } else if (place == "over") {
                //if (locationB.row+1 != -1) continue;

                int index; // index stores the top of stack B (without element)

                // find position of b that is clear
                for (int i = locationB.row; i < numBlocks; i++) {
                    if (blocks[i][locationB.col] == -1) {
                        index = i;
                        break;
                    }
                }

                // add stack a on top of index (stack b)
                for (int i = locationA.row; i < numBlocks; i++) {
                    if (blocks[i][locationA.col] == -1) break;

                    blocks[index][locationB.col] = blocks[i][locationA.col];
                    blocks[i][locationA.col] = -1;
                    index++;

                }
            }
        }

    }
    //printArray(blocks, numBlocks);

    // print out result
    for (int i = 0; i < numBlocks; i++) {
        cout << i << ":";

        for (int j = 0; j < numBlocks; j++) {
            if (blocks[j][i] == -1) break;
            cout << " " << blocks[j][i];
        }

        cout << endl;
    }

    return 0;
}
