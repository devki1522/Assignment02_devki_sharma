#include <iostream>
#include <fstream>
#include <string>
#include <vector>


struct STUDENT_DATA {
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
};

int main() {
#ifdef PRE_RELEASE
	std::ifstream inputFile("StudentData_Emails.txt");
#else
	std::ifstream inputFile("StudentData.txt");
#endif

	if (!inputFile.is_open()) {
		std::cout << "Error: Could not open the file." << std::endl;
		return 1;
	}

#ifdef PRE_RELEASE
	std::cout << "This application is running the PRE-RELEASE source code." << std::endl;
#else
	std::cout << "This application is running the STANDARD source code." << std::endl;
#endif

	std::string line;

	std::vector<STUDENT_DATA>students;

	while (std::getline(inputFile, line)) {
		size_t cpos = line.find(",");
		if (cpos == std::string::npos) {
			continue;
		}

		STUDENT_DATA student;
		student.firstName = line.substr(0, cpos);

		size_t epos = line.find(",", cpos + 1);
		if (epos == std::string::npos) {
			student.lastName = line.substr(cpos + 1);
		}
		else {
			student.lastName = line.substr(cpos + 1, epos - cpos - 1);
			student.emailAddress = line.substr(epos + 1);
		}

		students.push_back(student);
	}

	inputFile.close();

#ifdef _DEBUG
	for(size_t i= 0; i < students.size(); ++i) {
		std::cout << students[i].firstName << " " << students[i].lastName;
#ifdef PRE_RELEASE
		std::cout << " " << students[i].emailAddress;
#endif
		std::cout << std::endl;
	}
#endif

	return 1;
}