#include "Laba_N_3.h"

int main() {
    vector<Exhibit> exhibits;
    const string filename = "exhibits.txt";
    database::load_exhibits(exhibits, filename);

    int choice;
    do {
        cout << "\nKstovo's Regional Museum welcomes you!\n";
        cout << "\nMenu:\n";
        cout << "\n1. display exhibits on screen\n";
        cout << "2. add new exhibit\n";
        cout << "3. edit exgibit\n";
        cout << "4. delete(remove) exhibit\n";
        cout << "5. find exhibit\n";
        cout << "0. exit\n";
        cout << "\nChoose the number you should do\n";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            database::list_exhibits(exhibits);
            break;
        case 2:
            database::add_exhibit(exhibits);
            break;
        case 3:
            database::edit_exhibit(exhibits);
            break;
        case 4:
            database::delete_exhibit(exhibits);
            break;
        case 5:
            database::search_exhibits(exhibits);
            break;
        case 0:
            database::save_exhibits(exhibits, filename);
            cout << "Changes saved\n";
            break;
        default:
            cout << "Cause, error happend\n";
        }
    } while (choice != 0);

    return 0;
}