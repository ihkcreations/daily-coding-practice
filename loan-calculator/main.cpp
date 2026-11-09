#include <iostream>
#include <cmath>
#include <iomanip>

struct LoanDetails {
  double principal;
  double annualRate;
  int years;
};

void calculateLoan(const LoanDetails& loan) {
  double monthlyRate = loan.annualRate / 12.0 / 100.0;
  int totalMonths = loan.years * 12;
  double monthlyPayment = 0.0;
  if (monthlyRate > 0.0) {
    double factor = std::pow(1.0 + monthlyRate, totalMonths);
    monthlyPayment = loan.principal * monthlyRate * factor / (factor - 1.0);
  } else {
    monthlyPayment = loan.principal / totalMonths;
  }
  double totalPayment = monthlyPayment * totalMonths;
  double totalInterest = totalPayment - loan.principal;
  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Principal: $" << loan.principal << "\n";
  std::cout << "Annual Rate: " << loan.annualRate << "%\n";
  std::cout << "Term: " << loan.years << " years\n";
  std::cout << "Monthly Payment: $" << monthlyPayment << "\n";
  std::cout << "Total Interest: $" << totalInterest << "\n";
  std::cout << "----------------------------------------\n";
}

