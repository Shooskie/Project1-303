#include "Assignment.h"
#include "Date\StringTokenizer.h"

//////////////////////////////////////////////////toptip.c
void assignment::trim(string& s) {

	size_t p = s.find_first_not_of(" \t");
	s.erase(0, p);
	p = s.find_last_not_of(" \t");
	if (string::npos != p)
		s.erase(p + 1);

}
//////////////////////////////////////////////////toptip.c

string assignment::getDueDate() {
	return dueDate;
}

string assignment::getName() {
	return assignmentName;
}

void assignment::changecomplete() {
	if (!completed) {
		completed = true;
		return;
	}
	completed = false;
}

void assignment::setName(string description) {
	assignmentName = description;
}

void assignment::getReadData(istream& in) {
	string line;
	getline(in, line);
	String_Tokenizer st(line, ",");
	assignedDate = st.next_token();
	assignmentName = st.next_token();
	dueDate = st.next_token();
	status = st.next_token();
	trim(assignedDate);
	trim(assignmentName);
	trim(status);
	trim(dueDate);

	if (status == "completed" || status == "late") {
		completed = true;
	}
	else if (status == "assigned") {
		completed = false;
	}
	else {

	}

}
/* when reading in from the text file, are we assuming that the status will be a part of it? becuase we have the options to
change the status*/

/*basically what im getting at is that the file isnt real-time data, and that when you read in an item, its not like it was assigned
at that moment*/
bool assignment::getComplete() {
	return completed;
}

string assignment::getAssignedDate() {
	return assignedDate;
}

string assignment::getStatus() {
	return status;
}

void assignment::printAssignment(ostream& output) {
	output << "Assigned Date: " << getAssignedDate() << endl << "Description: " << getName() << endl;
	output << "Due Date: " << getDueDate() << endl << "Status: " << getStatus() << endl << endl;
}

void assignment::printTofile(ostream& output) {
	output << assignedDate << "," << assignmentName << "," << dueDate << "," << status;
}

bool assignment::compare(assignment toCompare) {
	Date date01(toCompare.getAssignedDate());
	if (date1 > date01) {
		return true;
	}
	return false;
}
void assignment::modifyDueDate(string& dueDate1) {
	dueDate = dueDate1;
	date2 = dueDate;
}}