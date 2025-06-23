using namespace std;
#include "buddy.hpp"
#include "worst-fit.hpp"
#include "circular-fit.hpp"

int menu()
{
    int c;
    cout << "Menu Options:" << endl;
    cout << "1. Option Buddy" << endl;
    cout << "2. Option Worst-Fit" << endl;
    cout << "3. Option Circular-Fit" << endl;
    cout << "4. Exit" << endl;
    cin >> c;
    return c;
}

int menu_buddy(string alocType)
{
    int c;
    cout << alocType << " Memory Management Options:" << endl;
    cout << "1. Allocate Memory" << endl;
    cout << "2. Desallocate Memory" << endl;
    cout << "3. Show Memory Status" << endl;
    cout << "4. Exit to Main Menu" << endl;
    cin >> c;
    return c;
}

int main()
{
    int c, main_size;

    cout << "Welcome to the Application!" << endl;
    cout << "Main memory size (Bytes): ";
    cin >> main_size;
    while (!check_pow_of_2(main_size))
    {
        cout << "Error: Memory size must be a power of 2." << endl;
        cout << "Main memory size (Bytes): ";
        cin >> main_size;
    }
    c = menu();
    while (c != 4)
    {
        switch (c)
        {
        case 1:
        {
            cout << "You selected Buddy Allocation." << endl;
            buddy b(main_size);
            int cb = menu_buddy("Buddy");
            while (cb != 4)
            {
                switch (cb)
                {
                case 1:
                {

                    int size;
                    string process_name;
                    cout << "Enter size to allocate (Bytes): ";
                    cin >> size;
                    cout << "Enter process name: ";
                    cin >> process_name;
                    b.in(process_name, size);
                    break;
                }
                case 2:
                {
                    string process_name;
                    cout << "Enter process to deallocate: ";
                    cin >> process_name;
                    b.out(process_name);
                    break;
                }
                case 3:
                {
                    cout << "Memory Status:" << endl;
                    b.str();
                    break;
                }
                default:
                    cout << "Invalid Buddy option. Try again." << endl;
                    break;
                }
                cb = menu_buddy("Buddy");
            }
            cout << "Returning to main menu." << endl;
            b.~buddy();
            cout << "Buddy memory management exited." << endl;
            break;
        }
        case 2:
        {
            cout << "You selected Worst-Fit Allocation." << endl;
            WorstFit b(main_size);
            int cb = menu_buddy("Worst-Fit");
            while (cb != 4)
            {
                switch (cb)
                {
                case 1:
                {

                    int size;
                    int process_name;
                    cout << "Enter size to allocate (Bytes): ";
                    cin >> size;
                    cout << "Enter process name: ";
                    cin >> process_name;
                    b.addMemory(process_name, size);
                    break;
                }
                case 2:
                {
                    int process_name;
                    cout << "Enter process to deallocate: ";
                    cin >> process_name;
                    b.removeMemory(process_name);
                    break;
                }
                case 3:
                {
                    cout << "Memory Status:" << endl;
                    b.printMemory();
                    break;
                }
                default:
                    cout << "Invalid Buddy option. Try again." << endl;
                    break;
                }
                cb = menu_buddy("Worst-Fit");
            }
            cout << "Returning to main menu." << endl;
            cout << "Worst-Fit memory management exited." << endl;
            break;
        }
        case 3:
        {
            cout << "You selected Circular-Fit Allocation." << endl;
            CircularFit b(main_size);
            int cb = menu_buddy("Circular-Fit");
            while (cb != 4)
            {
                switch (cb)
                {
                case 1:
                {

                    int size;
                    int process_name;
                    cout << "Enter size to allocate (Bytes): ";
                    cin >> size;
                    cout << "Enter process name: ";
                    cin >> process_name;
                    b.addMemory(process_name, size);
                    break;
                }
                case 2:
                {
                    int process_name;
                    cout << "Enter process to deallocate: ";
                    cin >> process_name;
                    b.removeMemory(process_name);
                    break;
                }
                case 3:
                {
                    cout << "Memory Status:" << endl;
                    b.printMemory();
                    break;
                }
                default:
                    cout << "Invalid Buddy option. Try again." << endl;
                    break;
                }
                cb = menu_buddy("Circular-Fit");
            }
            cout << "Returning to main menu." << endl;
            cout << "Circular-Fit memory management exited." << endl;
            break;
        }
        default:
            cout << "Invalid main menu option. Try again." << endl;
            break;
        }

        c = menu();
    }

    cout << "Finalizando o programa. Até logo!" << endl;
    return 0;
}
