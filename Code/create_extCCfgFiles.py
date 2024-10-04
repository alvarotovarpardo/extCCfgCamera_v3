import os
from modules import isolateClasses, classifyContent, copyInitParams, classifyInitDefault

def create_extCCfgCamGeneral_Header(HeaderFiles):
    isolateClasses(HeaderFiles)
    classifyContent()
    
    properties_path = os.path.join(os.getcwd(), 'bin\\header\\private\\extendedCCfgCamGeneral_properties.h')
    methods_path = os.path.join(os.getcwd(), 'bin\\header\\public\\extendedCCfgCamGeneral_methods.h')
    header_path = os.path.join(os.getcwd(),'C_Code')
    os.makedirs(header_path, exist_ok = True)
    header_file = os.path.join(header_path, 'config_camera.h')
    
    # Leer el archivo de propiedades
    with open(properties_path, 'r') as properties_file:
        properties_content = properties_file.read()
        

    # Leer el archivo de métodos
    with open(methods_path, 'r') as methods_file:
        methods_content = methods_file.read()

    # Crear el nuevo archivo unificado
    with open(header_file, 'w') as f:
        
        # Includes
        f.write("#include \"config_base.h\"\n")
        f.write("#include <vector>\n")
        f.write("#include <mutex>\n")
        
        f.write("\n\n\n")
        
        # Extras
        f.write("extern std::mutex mtxChangeHotConfig, mtxChangePointStart, mutexDNN;\n")
        f.write("extern std::mutex mtxChange, mtxSaveConfig;\n")
        
        f.write("\n\n")
        
        # Class
        f.write("class extendedCCfgCamGeneral : public CCfgClass\n")
        f.write("{\n")
        
            # Publico
        f.write("public:\n")
        f.write(methods_content)
        
        f.write("\n\n\n")
        
            # Private
        f.write("private:\n")
        f.write(properties_content)
        
        f.write("\n")
        
        # ending
        f.write("\n};")
        
        
        

    print("\n\n----------------------------------------------------")
    print(f"   Header successfully merged at: {header_path}.")
    print("----------------------------------------------------")
#%%

def create_extCCfgCamGeneral_Cpp(CppFiles):
    copyInitParams(CppFiles)
    classifyInitDefault()
    initContent_file = os.path.join(os.getcwd(), 'bin', 'cpp', 'initDefault', 'initDefaultContent.cpp')
    init_file = os.path.join(os.path.join(os.getcwd(), 'C_Code', 'config_camera.cpp'))

    # Leemos las propiedades inicializadas...
    with open(initContent_file, 'r') as file:
        initContent = file.read()
    
    # y las escribimos inicializadas. 
    with open(init_file, 'w') as f:
        
        # Includes
        f.write("#include \"config_camera.h\"\n")
        
        f.write("\n\n\n")
        
        # Extras
        
        
        # Class
        f.write("void extendedCCfgCamGeneral:: initDefault()\n")
        f.write("{\n")
        f.write(initContent)
        f.write("\n")
        
        # ending
        f.write("\n};")
        

        f.write("}")
    print(f"config_camera.cpp succesfully merged at {init_file}.")