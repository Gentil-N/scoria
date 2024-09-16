
file = open("/usr/include/vulkan/vulkan_core.h")

all_struct = []
start_saving = False
i = 0

class CStructVar:
    def __init__(self, line):
        elems = line.split()
        raw_name = elems[-1]
        self.types = elems[:-1]
        self.name = raw_name
    def get_full(self):
        full = ""
        for type in self.types:
            full += type + " "
        full += self.name
        return full
    def get_name(self):
        return self.name

class CStruct:
    def __init__(self, name):
        self.name = name
        self.cvar_list = []
    def append_cvar(self, line):
        self.cvar_list.append(CStructVar(line))
    def auto_print(self):
        print("# ", self.name, " ", self.convert_name_to_vktype())
        for cvar in self.cvar_list:
            print(cvar.get_full())
    def convert_name_to_vktype(self):
        curr_name = "VK_STRUCTURE_TYPE"
        for i in range(2, len(self.name)):
            if self.name[i].isupper() and not(self.name[i-1].isupper()) or self.name[i].isdigit():
                curr_name += "_"
            curr_name += self.name[i].upper()
        return curr_name
    def convert_name_to_func(self):
        return "vki" + self.name[2:]
    def get_init_null_function(self):
        init_function = "static inline " + self.name + " " + self.convert_name_to_func() + "_null()"
        init = "\t" + self.name + " init = {0};\n"
        for cvar in self.cvar_list:
            if cvar.get_name().find("sType") == 0:
                init += "\tinit.sType = " + self.convert_name_to_vktype() + ";\n"
                break
        init_function += " \n{\n" + init + "\treturn init;\n }\n"
        return init_function
    
    def get_init_function(self):
        init_function = "static inline " + self.name + " " + self.convert_name_to_func() + "("
        params = ""
        init = "\t" + self.name + " init = " + self.convert_name_to_func() + "_null()" + ";\n"
        added_count = 0
        for i in range(len(self.cvar_list)):
            if self.cvar_list[i].get_name().find("sType") == 0 or self.cvar_list[i].get_name().find("pNext") == 0 or self.cvar_list[i].get_name().find("flags") == 0:
                continue
            else:
                if added_count != 0:
                    params += ","
                init += "\tinit." + self.cvar_list[i].get_name() + " = " + self.cvar_list[i].get_name() + ";\n"
                params += self.cvar_list[i].get_full()
                added_count += 1
        init_function += params + ") \n{\n" + init + "\treturn init;\n }\n"
        return init_function


for line in file:
    if line.find("typedef struct") == 0:
        name = line.split(" ")[2].strip()
        start_saving = True
        all_struct.append(CStruct(name))
    elif start_saving:
        if line.find("}") != -1:
            start_saving = False
        else:
            param = line.strip()[:-1]
            if param.find("[") != -1:
                continue
            all_struct[-1].append_cvar(param)

file.close()

content = ""
for struct in all_struct:
    content += struct.get_init_null_function() + "\n"
    content += struct.get_init_function() + "\n"

write_file = open("./vki.h", "w")
write_file.write(content)
write_file.close()