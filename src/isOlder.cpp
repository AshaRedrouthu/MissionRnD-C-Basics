/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int validate(int day, int month, int year) {
	int range[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year % 4 == 0)
		range[1] = 29;
	if ((month > 0 && month <= 12) && (day <= range[month - 1]))
		return 1;
	else
		return 0;
}

int isOlder(char *dob1, char *dob2) {
	int r = -1;
	int d1 = (((dob1[0]) - '0') * 10) + (dob1[1] - '0');
	int m1 = (((dob1[3]) - '0') * 10) + (dob1[4] - '0');
	int y1 = (((dob1[6]) - '0') * 1000) + (((dob1[7]) - '0') * 100) + (((dob1[8]) - '0') * 10) + ((dob1[9]) - '0');
	int d2 = (((dob2[0]) - '0') * 10) + (dob2[1] - '0');
	int m2 = (((dob2[3]) - '0') * 10) + (dob2[4] - '0');
	int y2 = (((dob2[6]) - '0') * 1000) + (((dob2[7]) - '0') * 100) + (((dob2[8]) - '0') * 10) + ((dob2[9]) - '0');

	if (validate(d1, m1, y1) && validate(d2, m2, y2)){

		if (y1 > y2)
			r = 2;
		else if (y2 > y1)
			r = 1;
		else{
			if (m1 == m2&&d1 == d2)
				r = 0;
			else if (d1 < d2&&m1 == m2)
				r = 1;
			else if (d1 > d2&&m1 == m2)
				r = 2;
			else if (m1 < m2 && d1 == d2)
				r = 1;
			else
				if (m1>m2&&d1 == d2)
					r = 2;
		}
	}
	return r;
}
