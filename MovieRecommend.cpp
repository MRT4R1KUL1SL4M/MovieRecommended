#include <bits/stdc++.h>
using namespace std;

class Movie {
public:
    string name;
    double rating;

    Movie(string name, double rating) {
        this->name = name;
        this->rating = rating;
    }
};

void mergeLeftandRight(vector<Movie>& movies, int start, int end, int mid) {
    int i = start, j = mid + 1;
    vector<Movie> temp;
    
    while (i <= mid && j <= end) {
        if (movies[i].rating >= movies[j].rating) {
            temp.push_back(movies[i]);
            i++;
        } else {
            temp.push_back(movies[j]);
            j++;
        }
    }
    while (i <= mid) {
        temp.push_back(movies[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(movies[j]);
        j++;
    }
    for (int k = 0; k < temp.size(); k++) {
        movies[start + k] = temp[k];
    }
}

void mergeSort(vector<Movie>& movies, int start, int end) {
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(movies, start, mid);
    mergeSort(movies, mid + 1, end);
    mergeLeftandRight(movies, start, end, mid);
}

int main() {
    vector<Movie> movies;
    int choice;

    while (true) {
        cout << "\nMovie Recommendation System" << endl;
        cout << "1. Add Movie" << endl;
        cout << "2. Show Top Movies" << endl;
        cout << "3. Search Movie" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string name;
            double rating;
            cout << "Enter movie name: ";
            getline(cin, name);
            while (true) {
                cout << "Enter movie rating (0-10): ";
                cin >> rating;
                cin.ignore();
                if (rating < 0 || rating > 10) {
                    cout << "This is not a valid rating. Try again." << endl;
                } else {
                    break;
                }
            }
            movies.push_back(Movie(name, rating));
        }
        else if (choice == 2) {
            if (movies.empty()) {
                cout << "No movies available!" << endl;
                continue;
            }
            
            mergeSort(movies, 0, movies.size() - 1);
            cout << "\nTop Rated Movies:" << endl;
            for (const Movie& movie : movies) {
                cout << movie.name << " - " << movie.rating << "\n";
            }
        }
        else if (choice == 3) {
            string searchName;
            cout << "Enter movie name to search: ";
            getline(cin, searchName);
            
            bool found = false;
            for (size_t i = 0; i < movies.size(); i++) {
                if (movies[i].name == searchName) {
                    cout << "Movie found: " << movies[i].name << " - Rating: " << movies[i].rating << "\n";
                    found = true;
                    break;
                }
            }
            
            if (!found) {
                cout << "Movie not found!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
