-- DBMS Lab / Experiment 3 / 16014022050 (Group 6)

-- Positions Table
CREATE TABLE Positions (
    PositionId INT PRIMARY KEY,
    PositionName VARCHAR(255) NOT NULL,
    PositionDescription TEXT,
    Details TEXT
);

-- Allowances Table
CREATE TABLE Allowances (
    AllowanceId INT PRIMARY KEY,
    AllowanceName VARCHAR(255) NOT NULL,
    AllowanceDescription TEXT,
    Amount DECIMAL(10, 2) NOT NULL,
    PositionId INT,
    FOREIGN KEY (PositionId) REFERENCES Positions(PositionId)
);

-- Employees Table
CREATE TABLE Employees (
    EmployeeId INT PRIMARY KEY,
    SSNumber VARCHAR(15) UNIQUE NOT NULL,
    LastName VARCHAR(255) NOT NULL,
    FirstName VARCHAR(255) NOT NULL,
    Gender CHAR(1),
    DOB DATE,
    PositionId INT,
    FOREIGN KEY (PositionId) REFERENCES Positions(PositionId)
);

-- Vehicles Table
CREATE TABLE Vehicles (
    VehicleId INT PRIMARY KEY,
    VIN VARCHAR(17) NOT NULL,
    RegistrationNo VARCHAR(255) NOT NULL,
    Year INTEGER,
    Make VARCHAR(255),
    Model VARCHAR(255),
    Color VARCHAR(255),
    PositionId INT,
    FOREIGN KEY (PositionId) REFERENCES Positions(PositionId)
);

-- SalaryScales Table
CREATE TABLE SalaryScales (
    SalaryScalesCode INT PRIMARY KEY,
    SalaryScalesName VARCHAR(255) NOT NULL,
    SalaryScalesDescription TEXT,
    MinimumSalary DECIMAL(10, 2) NOT NULL,
    MaximumSalary DECIMAL(10, 2) NOT NULL,
    PositionId INT,
    FOREIGN KEY (PositionId) REFERENCES Positions(PositionId)
);
