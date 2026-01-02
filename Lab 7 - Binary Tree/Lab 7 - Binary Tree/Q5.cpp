#include <iostream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name;
    string position;
    Employee* left;
    Employee* right;
};

Employee* createEmployee(int id, string name, string position) {
    Employee* emp = new Employee;
    emp->id = id;
    emp->name = name;
    emp->position = position;
    emp->left = NULL;
    emp->right = NULL;
    return emp;
}

Employee* insert(Employee* root, int id, string name, string position) {
    if (root == NULL)
        return createEmployee(id, name, position);
    if (id < root->id)
        root->left = insert(root->left, id, name, position);
    else if (id > root->id)
        root->right = insert(root->right, id, name, position);
    return root;
}

void display(Employee* emp) {
    cout << "ID: " << emp->id << ", Name: " << emp->name << ", Position: " << emp->position << endl;
}

void inorder(Employee* root) {
    if (root != NULL) {
        inorder(root->left);
        display(root);
        inorder(root->right);
    }
}

void preorder(Employee* root) {
    if (root != NULL) {
        display(root);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Employee* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        display(root);
    }
}

Employee* findMin(Employee* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Employee* deleteEmployee(Employee* root, int id) {
    if (root == NULL) return NULL;

    if (id < root->id)
        root->left = deleteEmployee(root->left, id);
    else if (id > root->id)
        root->right = deleteEmployee(root->right, id);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if (root->left == NULL) {
            Employee* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Employee* temp = root->left;
            delete root;
            return temp;
        }
        Employee* temp = findMin(root->right);
        root->id = temp->id;
        root->name = temp->name;
        root->position = temp->position;
        root->right = deleteEmployee(root->right, temp->id);
    }
    return root;
}

bool updateEmployee(Employee* root, int id) {
    while (root != NULL) {
        if (id < root->id)
            root = root->left;
        else if (id > root->id)
            root = root->right;
        else {
            string newName, newPosition;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, newName);
            cout << "Enter new position: ";
            getline(cin, newPosition);
            root->name = newName;
            root->position = newPosition;
            return true;
        }
    }
    return false;
}

Employee* search(Employee* root, int id) {
    while (root != NULL) {
        if (id < root->id)
            root = root->left;
        else if (id > root->id)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

Employee* findMax(Employee* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

int height(Employee* root) {
    if (root == NULL) return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
}

int main() {
    Employee* root = NULL;
    int choice;

    while (true) {
        cout << "\n1. Add Employee\n";
        cout << "2. Display Employee Hierarchy\n";
        cout << "3. Delete Employee\n";
        cout << "4. Update Employee Details\n";
        cout << "5. Search Employee by ID\n";
        cout << "6. Find Lowest & Highest Employee IDs\n";
        cout << "7. Show Hierarchy Depth\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name, position;
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Position: ";
            getline(cin, position);
            root = insert(root, id, name, position);
        }
        else if (choice == 2) {
            cout << "\nIn-order Traversal:\n";
            inorder(root);
            cout << "\nPre-order Traversal:\n";
            preorder(root);
            cout << "\nPost-order Traversal:\n";
            postorder(root);
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Employee ID to delete: ";
            cin >> id;
            root = deleteEmployee(root, id);
            cout << "Deleted successfully (if ID was found)." << endl;
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Employee ID to update: ";
            cin >> id;
            if (!updateEmployee(root, id))
                cout << "Employee not found!" << endl;
            else
                cout << "Updated successfully!" << endl;
        }
        else if (choice == 5) {
            int id;
            cout << "Enter Employee ID to search: ";
            cin >> id;
            Employee* emp = search(root, id);
            if (emp == NULL)
                cout << "Employee not found!" << endl;
            else
                display(emp);
        }
        else if (choice == 6) {
            Employee* minEmp = findMin(root);
            Employee* maxEmp = findMax(root);
            if (minEmp && maxEmp) {
                cout << "Lowest ID Employee:\n";
                display(minEmp);
                cout << "Highest ID Employee:\n";
                display(maxEmp);
            } else {
                cout << "Tree is empty!" << endl;
            }
        }
        else if (choice == 7) {
            cout << "Hierarchy Depth: " << height(root) << endl;
        }
        else if (choice == 8) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}

