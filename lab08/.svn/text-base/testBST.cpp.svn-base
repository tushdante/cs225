#include "bst.h"
#include "coloredout.h"


//setUpIntPerfect()
//  - Parameter: tree by reference to set up
void setUpIntPerfect(BST<int, int> & tree){
    tree.insert(4, 1);
    tree.insert(2, 2);
    tree.insert(6, 3);
    tree.insert(1, 4);
    tree.insert(3, 5);
    tree.insert(5, 6);
    tree.insert(7, 7);
}

//setUpIntNonperfect()
//  - Parameter: tree by reference to set up
void setUpIntNonperfect(BST<int, int> & tree){
    tree.insert(6, 1);
    tree.insert(2, 2);
    tree.insert(5, 3);
    tree.insert(3, 4);
    tree.insert(4, 5);
    tree.insert(1, 6);
    tree.insert(7, 7);
}

//setUpCharNonperfect()
//  - Parameter: tree by reference to set up
void setUpCharNonperfect(BST<char, char> & tree){
    tree.insert('C', 'A');
    tree.insert('B', 'B');
    tree.insert('A', 'C');
    tree.insert('G', 'D');
    tree.insert('E', 'E');
    tree.insert('F', 'F');
    tree.insert('D', 'G');
}

//testFindHelper()
//  - Parameters: 2 vectors of template type T (assume T has operator<<)
//  - Returns:    true if the two are the same
template<typename T>
bool testFindHelper(vector<T> & expectedVals, vector<T> & retVals){
    bool notSame = false; //give them the benefit of the doubt!
    for(int i = 0; i < 7; i++){
        cout << "Looking for: " << expectedVals[i] << ".\t\t" << "Found: " << retVals[i] << endl;
        if(retVals[i]!=expectedVals[i])
            notSame = true;
    }
    return notSame;
}

//testTraversalHelper()
//  - Parameters: 2 vectors of template type T (assume T has operator<<)
//  - Returns:    true if the two are the same
template<typename T>
bool testTraversalHelper(vector<T> & expectedVals, vector<T> & retVals){
    bool notSame = false; //give them the benefit of the doubt!
    cout << "Your vector:\n";
    for(size_t i = 0; i < retVals.size(); i++)	
        cout << retVals[i] << " ";
    cout << endl;

    // test for correct values
	if (retVals.size() != expectedVals.size())
		return notSame = true;
    for(size_t i = 0; i < 7; i++){
        if(retVals[i] != expectedVals[i])
            notSame = true;
    }
    return notSame;
}

//testInsert()
void testInsert(){

    // test on perfect tree, integers
    BST<int, int> intP;
    setUpIntPerfect(intP);

    cout << "TESTING PERFECT BST (INTEGERS):\n";
    cout << "Your tree:\n";
    intP.print();

    cout << endl;

    // test on non-perfect tree, integers
    BST<int, int> intN;
    setUpIntNonperfect(intN);

    cout << "TESTING NON-PERFECT BST (INTEGERS):\n";
    cout << "Your tree:\n";
    intN.print();

    cout << endl;


    // test on non-perfect tree, characters
    BST<char, char> charN;
    setUpCharNonperfect(charN);

    cout << "TESTING NON-PERFECT BST (CHARACTERS):\n";
    cout << "Your tree:\n";
    charN.print();

    cout << endl;

    cout << "==================================================\n\n";

}

//testFind
//  - Returns: bool value of whether or not it worked
bool testFind(){
    bool breakEarly = false;

    // test on non-perfect tree, integers
    BST<int, int> intN;
    setUpIntNonperfect(intN);

    cout << "TESTING NON-PERFECT BST (INTEGERS):\n";

    vector<int> iretVals;
    vector<int> iexpectedVals;

    // set up expected value vector
    for(int i = 1; i <= 7; i++)
        iexpectedVals.push_back(i);

    // test find on each value
    iretVals.push_back(intN.find(6));
    iretVals.push_back(intN.find(2));
    iretVals.push_back(intN.find(5));
    iretVals.push_back(intN.find(3));
    iretVals.push_back(intN.find(4));
    iretVals.push_back(intN.find(1));
    iretVals.push_back(intN.find(7));

    breakEarly = testFindHelper(iexpectedVals, iretVals);
    cout<< "Find was...";

    // check if same
    if(breakEarly)
	{
		cout << "INCORRECT!\n\n";
    	cout << "==================================================\n\n";
		return false;
	}

    cout << "CORRECT!\n\n";

    // test on non-perfect tree, characters
    BST<char, char> charN;
    setUpCharNonperfect(charN);

    cout << "TESTING NON-PERFECT BST (CHARACTERS):\n";

    vector<char> cretVals;
    vector<char> cexpectedVals;

    // set up expected value vector
    for(char i = 'A'; i <= 'G'; i++)
        cexpectedVals.push_back(i);

    // test find on each value
    cretVals.push_back(charN.find('C'));
    cretVals.push_back(charN.find('B'));
    cretVals.push_back(charN.find('A'));
    cretVals.push_back(charN.find('G'));
    cretVals.push_back(charN.find('E'));
    cretVals.push_back(charN.find('F'));
    cretVals.push_back(charN.find('D'));

    breakEarly = testFindHelper(cexpectedVals, cretVals);
    cout<< "Find was...";

	if (breakEarly)
		cout << "INCORRECT!\n";
	else
   		cout << "CORRECT!\n";

    cout << "==================================================\n\n";

    // check if same
    return !breakEarly;
}

//testRemove()
void testRemove(){

    // test on non-perfect tree, integers
    BST<int, int> intN;
    setUpIntNonperfect(intN);

    cout << "TESTING NON-PERFECT BST (INTEGERS):\n";
    cout << "Before removals:\n";
    intN.print();

    cout << "Remove no child (1)\n";
    intN.remove(1);
    cout << "Your tree:\n";
    intN.print();

    cout << endl;

    cout << "Remove one child (5)\n";
    intN.remove(5);
    cout << "Your tree:\n";
    intN.print();

    cout << endl;

    cout << "Remove two child (6)\n";
    intN.remove(6);
    cout << "Your tree:\n";
    intN.print();

    cout << endl;


    // test on non-perfect tree, characters
    BST<char, char> charN;
    setUpCharNonperfect(charN);

    cout << "TESTING NON-PERFECT BST (CHARACTERS):\n";
    cout << "Before removals:\n";
    charN.print();

    cout << "Applying several removals...\n";
    charN.remove('G');
    charN.remove('A');
    charN.remove('B');
    charN.remove('E');

    cout << "Your tree:\n";
    charN.print();

    cout << "==================================================\n\n";

}

//testKeySort()
//  - Returns: bool value of whether or not it worked
bool testKeySort(){
    bool breakEarly = false;

    // test on non-perfect tree, integers
    BST<int, int> intN;
    setUpIntNonperfect(intN);

    cout << "TESTING NON-PERFECT BST (INTEGERS):\n";

    vector<int> iretVals = intN.keySort();
    vector<int> iexpectedVals;

    iexpectedVals.push_back(6);
    iexpectedVals.push_back(2);
    iexpectedVals.push_back(4);
    iexpectedVals.push_back(5);
    iexpectedVals.push_back(3);
    iexpectedVals.push_back(1);
    iexpectedVals.push_back(7);

    breakEarly = testTraversalHelper(iexpectedVals, iretVals);
    cout << "Key Sort was...";
    if(breakEarly)
	{
		cout << "INCORRECT!\n\n";
    	cout << "==================================================\n\n";
		return false;
	}

    cout << "CORRECT!\n\n";

    // test on non-perfect tree, characters
    BST<char, char> charN;
    setUpCharNonperfect(charN);

    cout << "TESTING NON-PERFECT BST (CHARACTERS):\n";

    vector<char> cretVals = charN.keySort();
    vector<char> cexpectedVals;

    cexpectedVals.push_back('C');
    cexpectedVals.push_back('B');
    cexpectedVals.push_back('A');
    cexpectedVals.push_back('G');
    cexpectedVals.push_back('E');
    cexpectedVals.push_back('F');
    cexpectedVals.push_back('D');	

    breakEarly = testTraversalHelper(cexpectedVals, cretVals);
    cout << "Key Sort was...";

	if (breakEarly)
		cout << "INCORRECT!\n";
	else
   		cout << "CORRECT!\n";

    cout << "==================================================\n\n";

    // check if same
    return !breakEarly;
}

//testLevelOrder
//  - Returns: bool value of whether or not it worked
bool testLevelOrder(){
    bool breakEarly = false;

    // test on non-perfect tree, integers
    BST<int, int> intN;
    setUpIntNonperfect(intN);

    cout << "TESTING NON-PERFECT BST (INTEGERS):\n";

    vector<int> iretVals = intN.levelOrder();
    vector<int> iexpectedVals;

    iexpectedVals.push_back(1);
    iexpectedVals.push_back(2);
    iexpectedVals.push_back(7);
    iexpectedVals.push_back(6);
    iexpectedVals.push_back(3);
    iexpectedVals.push_back(4);
    iexpectedVals.push_back(5);

    breakEarly = testTraversalHelper(iexpectedVals, iretVals);
    cout << "Level Order was...";
    if(breakEarly)
	{
		cout << "INCORRECT!\n\n";
		return false;
	}
    
	cout << "CORRECT!\n\n";

    // test on non-perfect tree, characters
    BST<char, char> charN;
    setUpCharNonperfect(charN);

    cout << "TESTING NON-PERFECT BST (CHARACTERS):\n";

    vector<char> cretVals = charN.levelOrder();
    vector<char> cexpectedVals;

    cexpectedVals.push_back('A');
    cexpectedVals.push_back('B');
    cexpectedVals.push_back('D');
    cexpectedVals.push_back('C');
    cexpectedVals.push_back('E');
    cexpectedVals.push_back('G');
    cexpectedVals.push_back('F');	

    breakEarly = testTraversalHelper(cexpectedVals, cretVals);
    cout << "Level Order was...";
    if(breakEarly)
        cout << "INCORRECT!\n";
    else
		cout << "CORRECT!\n";

    return !breakEarly;
}

//main()
int main(int argc, char** argv){
    bool is_colored = (argc > 1 && tolower(argv[1][0]) == 'c') && isatty(STDOUT_FILENO);
    colored_out coloroutput;
    if (is_colored)
    {
        coloroutput.set_expected_file("soln_testbst.out");
        int status = coloroutput.start();
        if (status < 0) return 0;
    }

    cout << "\t\t\tTESTING INSERTIONS\n\n";
    testInsert();

    cout << "\t\t\tTESTING FINDS\n\n";
    testFind();

    cout << "\t\t\tTESTING REMOVALS\n\n";
    testRemove();

    cout << "\t\t\tTESTING KEY SORT\n\n";
    testKeySort();

    cout << "\t\t\tTESTING LEVEL ORDER\n\n";
    testLevelOrder();

    return 0;
}
