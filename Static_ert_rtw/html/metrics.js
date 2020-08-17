function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 15502};
	 this.metricsArray.var["rtInf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 8};
	 this.metricsArray.var["rtInfF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 4};
	 this.metricsArray.var["rtM_"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 8};
	 this.metricsArray.var["rtMinusInf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 8};
	 this.metricsArray.var["rtMinusInfF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 4};
	 this.metricsArray.var["rtNaN"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 8};
	 this.metricsArray.var["rtNaNF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 4};
	 this.metricsArray.var["rtPrevZCX"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 1};
	 this.metricsArray.var["rtU"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 32};
	 this.metricsArray.var["rtY"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	size: 29};
	 this.metricsArray.fcn["Static.c:factorial"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["Static.c:linspace"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 12,
	stackTotal: 12};
	 this.metricsArray.fcn["Static.c:sin_h"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["Static_initialize"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["Static_step"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 52,
	stackTotal: 64};
	 this.metricsArray.fcn["fabs"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["floor"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memcpy"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["memset"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\string.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["pow"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtGetInf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetInfF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetMinusInf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetMinusInfF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtGetNaN"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 20,
	stackTotal: 24};
	 this.metricsArray.fcn["rtGetNaNF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["rtIsInf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsInfF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaN"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rtIsNaNF"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["rt_InitInfAndNaN"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 0,
	stackTotal: 24};
	 this.metricsArray.fcn["rt_ZCFcn"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 10,
	stackTotal: 10};
	 this.metricsArray.fcn["rt_powf_snf"] = {file: "F:\\Master_Studies\\Semester_2\\Model_Based_Simulation\\Labs\\Lab_4\\Practical_work\\Static_ert_rtw\\Static.c",
	stack: 12,
	stackTotal: 12};
	 this.metricsArray.fcn["sin"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["sqrt"] = {file: "F:\\Program Files\\MATLAB\\R2018a\\sys\\lcc\\include\\math.h",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data; }; 
	 this.codeMetricsSummary = '<a href="Static_metrics.html">Global Memory: 15608(bytes) Maximum Stack: 52(bytes)</a>';
	}
CodeMetrics.instance = new CodeMetrics();
