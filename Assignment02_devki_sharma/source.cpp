#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
};

int main() {
	std::ifstream inputFile("StudentData.txt");

	if (!inputFile.is_open()) {
		std::cout << "Error: Could not open the file." << std::endl;
		return 1;
	}

	std::string line;

	std::vector<STUDENT_DATA>students;

	while (std::getline(inputFile, line)) {
		size_t cpos = line.find(",");
		if (cpos == std::string::npos) {
			continue;
		}

		STUDENT_DATA student;
		student.firstName = line.substr(0, cpos);
		student.lastName = line.substr(cpos + 1);

		students.push_back(student);

		
	}
	std::cout << students.size();

	return 1;
}