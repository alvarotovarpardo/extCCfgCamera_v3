<em> Extended Config Camera </em>

Este repositorio tiene como objetivo la creación de las clases CCfgCamGeneral de manera extendida y unificada para las cuatro aplicaciones de Redlook.

La ejecución del archivo main.py genera un output en la carpeta 'C_Code', conteniendo:
1) config_camera.h -> Clase extendedCCfgCamGeneral con properties/getters&setters de la configuración de la cámara
2) config_camera.cpp -> Inicialización de parámetros (función initDefault())
3) config_base.h -> clase de la que config_camera.h hereda. Aquí se define initDefault()
4) config_base.cpp -> constructor y destructor
5) main.cpp -> un main vacío para la compilación.

Todos los archivos C++ generados incluyen los #includes, #DEFINE necesarios para la compilación.

FALTARÍA automatizar la detección de propiedades y métodos duplicados pero no definidos de manera unívoca.
P.ej., int m_iFocalLength, double m_dFocalLength, con sus correspondientes getters&setters.
Está en proceso.
