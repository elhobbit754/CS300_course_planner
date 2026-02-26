#pragma once

#include <string>
#include "../include/BinarySearchTree.hpp"

class DataService {
    public:
        void loadCourses(const std::string& csvPath);
        void showCourses();
        Course searchCourse(const std::string& id);

    private:
        BinarySearchTree store;
};
