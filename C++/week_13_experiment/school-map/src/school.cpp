#include "../include/school.h"
extern int INF;
extern int adistance[4][4];

void printMap() {  

	cout<<"                    _C______"<<adistance[2][3]<<"______D_"<<endl;
    cout<<"                   // \\           ||"<<endl;
	cout<<"                " <<adistance[0][2]<<" //   \\_"<<adistance[1][2]<<"__      ||"<<endl;
    cout<<"                 //          \\    ||"<<adistance[1][3]<<endl;
	cout<<"                //            \\   ||"<<endl;
    cout<<"               A______"<<adistance[0][1]<<"_______\\__B"<<endl;
	cout<<endl<<endl;
    cout << endl;   

    // Point printout  
    cout << "Points:" << endl;  
    cout << "0: A" << '\t' << "1: B" << '\t' << "2: C" << '\t' << "3: D" << endl;  

    // Print distances  
    cout << "Distances:" << endl;  
    if (adistance[0][1] != INF) cout << "A-B: " << adistance[0][1] << endl;  
    else cout << "A-B: No edge" << endl;  
    if (adistance[0][2] != INF) cout << "A-C: " << adistance[0][2] << endl;  
    else cout << "A-C: No edge" << endl;  
    if (adistance[1][3] != INF) cout << "B-D: " << adistance[1][3] << endl;  
    else cout << "B-D: No edge" << endl;  
    if (adistance[1][2] != INF) cout << "B-C: " << adistance[1][2] << endl;  
    else cout << "B-C: No edge" << endl;  
    if (adistance[2][3] != INF) cout << "C-D: " << adistance[2][3] << endl;  
    else cout << "C-D: No edge" << endl;  
}  
