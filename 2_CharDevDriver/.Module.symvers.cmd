cmd_/home/nemesis/Desktop/Study_Plan/GithubRepositories/LinuxKernelDevelopment_Playground/2_CharDevDriver/Module.symvers := sed 's/\.ko$$/\.o/' /home/nemesis/Desktop/Study_Plan/GithubRepositories/LinuxKernelDevelopment_Playground/2_CharDevDriver/modules.order | scripts/mod/modpost -m -a  -o /home/nemesis/Desktop/Study_Plan/GithubRepositories/LinuxKernelDevelopment_Playground/2_CharDevDriver/Module.symvers -e -i Module.symvers   -T -