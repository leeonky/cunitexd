#! /usr/bin/env ruby

def start_comma params_count
	return ', ' if params_count>0
	return ''
end

def arg_list params_count
	params_count.times.map{|t| "t#{t+1}"}.join ', '
end

def end_line params_count
	return '\\' if params_count>0
	return ''
end

def extern_params_list params_count
	return params_count.times.map{|i| "	extern t#{i+1} func ## _p#{i+1};"}.join("\\\n")+"\n" if params_count>0
	return ''
end

def define_params_list params_count
	return params_count.times.map{|i| "	t#{i+1} func ## _p#{i+1};\\\n"}.join
end

def fun_params_list params_count
	return params_count.times.map{|i| "t#{i+1} p#{i+1}"}.join ', '
end

def record_args params_count
	return params_count.times.map{|i| "		func ## _p#{i+1} = p#{i+1};\\\n"}.join
end

def call_params_list params_count
	params_count.times.map{|t| "p#{t+1}"}.join ', '
end

ARGV[0].to_i.times do |params_count|
	puts "#define extern_mock_void_function_#{params_count}(func#{start_comma params_count}#{arg_list params_count}) \\"
	puts "	extern int func ## _times;\\"
	puts "	extern int func ## _set_return;\\"
	puts "	extern void (*mock_ ## func)(#{arg_list params_count});#{end_line params_count}"
	print extern_params_list(params_count);
	puts "#define mock_void_function_#{params_count}(func#{start_comma params_count}#{arg_list params_count}) \\"
	puts "	int func ## _times;\\"
	puts "	int func ## _set_return;\\"
	print define_params_list(params_count);
	puts "	void (*mock_ ## func)(#{arg_list params_count});\\"
	puts "	void func(#{fun_params_list params_count}) {\\"
	puts "		++func ## _times;\\"
	print record_args(params_count)
	puts "		if(mock_ ## func)\\"
	puts "			mock_ ## func(#{call_params_list params_count});\\"
	puts "	}"
	puts ""
end

ARGV[0].to_i.times do |params_count|
	puts "#define extern_mock_function_#{params_count}(rtype, func#{start_comma params_count}#{arg_list params_count}) \\"
	puts "	extern int func ## _times;\\"
	puts "	extern int func ## _set_return;\\"
	puts "	extern rtype func ## _return_value;\\"
	puts "	extern rtype (*mock_ ## func)(#{arg_list params_count});#{end_line params_count}"
	print extern_params_list(params_count);
	puts "#define mock_function_#{params_count}(rtype, func#{start_comma params_count}#{arg_list params_count}) \\"
	puts "	int func ## _times;\\"
	puts "	int func ## _set_return;\\"
	puts "	rtype func ## _return_value;\\"
	print define_params_list(params_count);
	puts "	rtype (*mock_ ## func)(#{arg_list params_count});\\"
	puts "	rtype func(#{fun_params_list params_count}) {\\"
	puts "		static rtype default_result;\\"
	puts "		++func ## _times;\\"
	print record_args(params_count)
	puts "		if(mock_ ## func)\\"
	puts "			return mock_ ## func(#{call_params_list params_count});\\"
	puts "		return func ## _set_return ? func ## _return_value : default_result;\\"
	puts "	}"
	puts ""
end

