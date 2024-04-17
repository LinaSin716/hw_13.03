
// без последнего пункта

#include<iostream>
#include<fstream>
#include<ctime>

#include<vector>
#include<string>
#include<algorithm>

struct Worker
{
	int num = 0;
	std::string name = "";
	std::string shift = ""; //смена
	int salary = 0; // зарплата
};

std::vector<Worker> Make_arr(int n);

std::vector<Worker> Day_workers(int n, std::vector<Worker> workers);
std::vector<Worker> Night_workers(int n, std::vector<Worker> workers);

void Print_worker(int n, std::vector<Worker> workers);
void Print_day_workers(std::vector<Worker> workers);
void Print_night_workers(std::vector<Worker> workers);

std::vector<Worker> Max_salaries_day(std::vector<Worker> day_workers, std::vector<Worker> workers);
std::vector<Worker> Max_salaries_night(std::vector<Worker> night_workers, std::vector<Worker> workers);
std::vector<Worker> Max_salaries_all(std::vector<Worker> workers);

std::vector<Worker> Min_salaries_day(std::vector<Worker> day_workers, std::vector<Worker> workers);
std::vector<Worker> Min_salaries_night(std::vector<Worker> night_workers, std::vector<Worker> workers);
std::vector<Worker> Min_salaries_all(std::vector<Worker> workers);

//==============================================================================================================================

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	std::ofstream file;
	file.open("test.txt");

	int n;
	std::cout << "Введите кол-во сотрудников(>2): ";
	std::cin >> n;
	std::vector<Worker> workers = Make_arr(n);
	std::cout << "Все сотрудники: \n\n";
	for (int i = 0; i < n; i++)
	{
		Print_worker(i, workers);
	}
	std::cout << "\n\n";

	std::cout << "=========================================================\n\n";
	//#4
	std::vector<Worker> day_workers = Day_workers(n, workers);
	std::vector<Worker> night_workers = Night_workers(n, workers);
	std::cout << "Дневная смена: \n\n";
	Print_day_workers(day_workers);
	std::cout << "Ночная смена: \n\n";
	Print_night_workers(night_workers);

	std::cout << "=========================================================\n\n";
	//#5
	std::cout << "Три сотрудника с самой высокой зп среди дневных: \n\n";
	std::vector<Worker> arr_into_file_day = Max_salaries_day(day_workers, workers);
	std::cout << "Ночных:\n\n";
	std::vector<Worker> arr_into_file_night = Max_salaries_night(night_workers, workers);
	std::cout << "Всех: \n\n";
	std::vector<Worker> arr_into_file_all = Max_salaries_all(workers);

	std::cout << "=========================================================\n\n";
	//#6
	file << "=========================================================\n\n";
	file << "Три сотрудника с самой высокой зп среди дневных: \n\n";
	for (auto& worker : arr_into_file_day)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}
	file << "Ночных:\n\n";
	for (auto& worker : arr_into_file_night)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}
	file << "Всех:\n\n";
	for (auto& worker : arr_into_file_all)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}

	//#7
	std::cout << "Три сотрудника с самой низкой зп среди дневных: \n\n";
	arr_into_file_day = Min_salaries_day(day_workers, workers);
	std::cout << "Ночных: \n\n";
	arr_into_file_night = Min_salaries_night(night_workers, workers);
	std::cout << "Всех: \n\n";
	arr_into_file_all = Min_salaries_all(workers);

	std::cout << "=========================================================\n\n";
	//#8	
	file << "=========================================================\n\n";
	file << "Три сотрудника с самой низкой зп среди дневных: \n\n";
	for (auto& worker : arr_into_file_day)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}
	file << "Ночных: \n\n";
	for (auto& worker : arr_into_file_night)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}
	file << "Всех: \n\n";
	for (auto& worker : arr_into_file_all)
	{
		file << "Номер\t" << worker.num << "\n" <<
			"Имя\t" << worker.name << "\n" <<
			"Смена\t" << worker.shift << "\n" <<
			"Зарплата\t" << worker.salary << "\n\n";
	}

	file.close();
	return 0;
}

//==============================================================================================================================

std::vector<Worker> Make_arr(int n) {

	std::vector<std::string> shifts = { "Дневная", "Ночная" };
	int rand_shift = rand() % 2;
	std::string name_num;
	std::string shift_num;
	int salary_num = rand() % 1000000;
	int num;

	std::vector<Worker> arr_workers(n);

	for (int i = 0; i < n; i++)
	{
		num = i + 1;
		name_num = "Сотрудник" + std::to_string(num);
		shift_num = shifts[rand_shift];

		arr_workers[i].name = name_num;
		arr_workers[i].num = num;
		arr_workers[i].salary = salary_num;
		arr_workers[i].shift = shift_num;

		salary_num = rand() % 1000000;
		rand_shift = rand() % 2;
	}
	
	return arr_workers;
}

std::vector<Worker> Day_workers(int n, std::vector<Worker> workers) {
	std::vector<Worker> day_workers;
	int i = 0;
	for (auto& worker : workers)
	{
		if (worker.shift == "Дневная") {
			day_workers.push_back(worker);
		}
		i++;
	}
	return day_workers;
}

std::vector<Worker> Night_workers(int n, std::vector<Worker> workers) {
	std::vector<Worker> night_workers;
	int i = 0;
	for (auto& worker : workers)
	{
		if (worker.shift == "Ночная") {
			night_workers.push_back(worker);
		}
		i++;
	}
	return night_workers;
}

void Print_worker(int n, std::vector<Worker> workers) {
	Worker worker = workers[n];
	std::cout << "Номер\t\t" << worker.num << "\n" <<
		"Имя\t\t" << worker.name << "\n" <<
		"Смена\t\t" << worker.shift << "\n" <<
		"Зарплата\t" << worker.salary << "\n\n";
}

void Print_day_workers(std::vector<Worker> day_workers) {
	int i = 0;
	for (auto& worker : day_workers)
	{
		Print_worker(i, day_workers);
		i++;
	}
	std::cout << "\n";
}

void Print_night_workers(std::vector<Worker> night_workers) {
	int i = 0;
	for (auto& worker : night_workers)
	{
		Print_worker(i, night_workers);
		i++;
	}
	std::cout << "\n";
}

std::vector<Worker> Max_salaries_day(std::vector<Worker> day_workers, std::vector<Worker> workers){
	int size = day_workers.size();
	
	std::vector<std::pair<int, int>> sort_day_workers;
	int i = 0;
	for (auto& worker : day_workers)
	{
		sort_day_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_day_workers.begin(), sort_day_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_day_workers[size - 1].second - 1, workers);
		arr.push_back(workers[sort_day_workers[size - 1].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_day_workers[size - 2].second - 1, workers);
		arr.push_back(workers[sort_day_workers[size - 2].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_day_workers[size - 3].second - 1, workers);
		arr.push_back(workers[sort_day_workers[size - 3].second - 1]);
	}

	return arr;
}
std::vector<Worker> Max_salaries_night(std::vector<Worker> night_workers, std::vector<Worker> workers) {
	int size = night_workers.size();

	std::vector<std::pair<int, int>> sort_night_workers;
	int i = 0;
	for (auto& worker : night_workers)
	{
		sort_night_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_night_workers.begin(), sort_night_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_night_workers[size - 1].second - 1, workers);
		arr.push_back(workers[sort_night_workers[size - 1].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_night_workers[size - 2].second - 1, workers);
		arr.push_back(workers[sort_night_workers[size - 2].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_night_workers[size - 3].second - 1, workers);
		arr.push_back(workers[sort_night_workers[size - 3].second - 1]);
	}
	
	return arr;
}
std::vector<Worker> Max_salaries_all(std::vector<Worker> workers) {
	int size = workers.size();

	std::vector<std::pair<int, int>> sort_workers;
	int i = 0;
	for (auto& worker : workers)
	{
		sort_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_workers.begin(), sort_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_workers[size - 1].second - 1, workers);
		arr.push_back(workers[sort_workers[size - 1].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_workers[size - 2].second - 1, workers);
		arr.push_back(workers[sort_workers[size - 2].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_workers[size - 3].second - 1, workers);
		arr.push_back(workers[sort_workers[size - 3].second - 1]);
	}

	return arr;
}

std::vector<Worker> Min_salaries_day(std::vector<Worker> day_workers, std::vector<Worker> workers) {
	int size = day_workers.size();

	std::vector<std::pair<int, int>> sort_day_workers;
	int i = 0;
	for (auto& worker : day_workers)
	{
		sort_day_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_day_workers.begin(), sort_day_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_day_workers[0].second - 1, workers);
		arr.push_back(workers[sort_day_workers[0].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_day_workers[1].second - 1, workers);
		arr.push_back(workers[sort_day_workers[1].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_day_workers[2].second - 1, workers);
		arr.push_back(workers[sort_day_workers[2].second - 1]);
	}

	return arr;
}
std::vector<Worker> Min_salaries_night(std::vector<Worker> night_workers, std::vector<Worker> workers) {
	int size = night_workers.size();

	std::vector<std::pair<int, int>> sort_night_workers;
	int i = 0;
	for (auto& worker : night_workers)
	{
		sort_night_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_night_workers.begin(), sort_night_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_night_workers[0].second - 1, workers);
		arr.push_back(workers[sort_night_workers[0].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_night_workers[1].second - 1, workers);
		arr.push_back(workers[sort_night_workers[1].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_night_workers[2].second - 1, workers);
		arr.push_back(workers[sort_night_workers[2].second - 1]);
	}
	return arr;
}
std::vector<Worker> Min_salaries_all(std::vector<Worker> workers) {
	int size = workers.size();

	std::vector<std::pair<int, int>> sort_workers;
	int i = 0;
	for (auto& worker : workers)
	{
		sort_workers.push_back({ worker.salary, worker.num });
		i++;
	}
	std::sort(sort_workers.begin(), sort_workers.end());
	std::vector<Worker> arr;

	if (size > 0) {
		Print_worker(sort_workers[0].second - 1, workers);
		arr.push_back(workers[sort_workers[0].second - 1]);
	}
	if (size > 1) {
		Print_worker(sort_workers[1].second - 1, workers);
		arr.push_back(workers[sort_workers[1].second - 1]);
	}
	if (size > 2) {
		Print_worker(sort_workers[2].second - 1, workers);
		arr.push_back(workers[sort_workers[2].second - 1]);
	}

	return arr;
}
