from modules import copyConfigBaseHeader, classifyConfigBaseHeader
import os

def createConfigBaseHeader(input_file):
    copyConfigBaseHeader(input_file)
    classifyConfigBaseHeader()
    
    file_path = os.path.join(os.getcwd(), 'bin', 'header', 'config_base', 'config_base.h')
    header_file = os.path.join(os.getcwd(),'C_Code', 'config_base.h')
    
    with open(file_path, 'r') as file:
        content = file.read()
        
    with open(header_file, 'w') as f:
        
        # Defines
        f.write("#ifndef CCONFIG_BASE_H_\n")
        f.write("#define CCONFIG_BASE_H_\n")
        f.write("\n")
        f.write("#define CFGCLASS_MAX_NAME 20\n")
        f.write("#define CFG_MAX_DESCRIPTION 30\n")
        f.write("#define CFG_MAX_SMALL_ID 3\n")
        f.write("\n")
        f.write("#define CONFIG_MAX_PATH 256\n")
        f.write("#define CONFIG_MAX_IP 16\n")
        f.write("#define CONFIG_MAX_HOST 256\n")
        f.write("\n")
        f.write("#define MAX_SERIAL_PORTS_CAMERA 3\n")
        f.write("\n")
        
        # Includes
        f.write("#include <iostream>\n")
        f.write("#include <fstream>\n")
        f.write("#include <cstring>\n")
        
        # Class content
        f.write(content)
        
        # End of file
        f.write("\n\n\n#endif /* CCONFIG_BASE_H_ */")
    
        
    
    
    print('config_base.h creado en C_Code')
    
    
def createConfigBaseCpp():
    cpp_file = os.path.join(os.getcwd(), 'C_Code', 'config_base.cpp')
    
    with open(cpp_file, 'w') as f:
        f.write('#include "config_base.h"\n\n')
        f.write('CCfgClass::CCfgClass(const char *szName)\n')
        f.write('{\n')
        f.write('    strncpy_s(m_szName, szName, CFGCLASS_MAX_NAME);\n')
        f.write('}\n\n')
        f.write('CCfgClass::~CCfgClass()\n')
        f.write('{\n')
        f.write('\n')
        f.write('}\n')
        
        
        
        
        