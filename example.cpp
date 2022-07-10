//
// Created by Lastprism on 2020/6/5.
//

#include "mysql_connector.h"
#include "thread_pool.h"
#include <iostream>
#include <cstdio>

#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD "root"
#define DATABASE "test"

using namespace std;

void use_mysql_connector() {
	mysql_connector mc;
	if (mc.connect_to(SERVER, USER, PASSWORD, DATABASE)) {

		cerr << "connect error : " << mc.error() << endl;
		exit(1);

	}
	auto res = mc.query("select * from test_blob");

	if (res.second) {
		cerr << "query error : " << mc.error() << endl;
		exit(1);
	}

	for (auto& row : res.first) {
		for (auto& col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
}

int main() {
	use_mysql_connector();
	return 0;
}


