#include <iostream>
#include <stack>
using namespace std;


struct Move {
    int disk;  // Disk number
    char fromRod, toRod, auxRod;  
};


void towerOfHanoi(int numDisks, char fromRod, char toRod, char auxRod) {
    stack<Move> moves;  
    

    Move initialMove = {numDisks, fromRod, toRod, auxRod};
    moves.push(initialMove);


    while (!moves.empty()) {

        Move currentMove = moves.top();
        moves.pop();
        

        switch (currentMove.disk) {
            case 1:

                cout << "Move disk 1 from " << currentMove.fromRod << " to " << currentMove.toRod << endl;
                break;
            
            default:
                moves.push({currentMove.disk - 1, currentMove.auxRod, currentMove.toRod, currentMove.fromRod});
                
                
                cout << "Move disk " << currentMove.disk << " from " << currentMove.fromRod << " to " << currentMove.toRod << endl;
                
                
                moves.push({currentMove.disk - 1, currentMove.fromRod, currentMove.auxRod, currentMove.toRod});
                break;
        }
    }
}

int main() {
    int numDisks;
    
    
    cout << "Enter the number of disks: ";
    cin >> numDisks;
    

    towerOfHanoi(numDisks, 'A', 'C', 'B'); 
    
    return 0;
}
