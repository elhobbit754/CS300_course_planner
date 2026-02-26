#include <csv.hpp>
#include "../include/DataService.hpp"
#include "../include/BinarySearchTree.hpp"

using namespace std;

void DataService::loadCourses(const std::string& csvPath) {
    csv::CSVReader reader(csvPath);

    size_t counter = 0;

    for (auto& row : reader) {
        Course course;
        course.id = row[0].get<>();
        course.title = row[1].get<>();

        for (size_t i = 2; i < row.size(); ++i) {
            string prereq = row[i].get<>();

            if (!prereq.empty()) {
                course.prereqs.push_back(prereq);
            }
        }

        store.Insert(course);
        counter++;
    }

    cout << counter << " courses read" << endl;
}

void DataService::showCourses() {
    store.InOrder();
}

Course DataService::searchCourse(const std::string& id) {
    return store.Search(id);
}
