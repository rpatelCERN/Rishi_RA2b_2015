import os
for i in range(0,500):
	index=i
	start=(i*60000)
	finish=(i+1)*60000
	f=open("bsub_%d.sh" %i, 'w')
	f.write("#!/bin/sh\n")
#	f.write("#SBATCH -J SingleTauArray\n")
#	f.write("#SBATCH -p background-4g\n")
#	f.write("#SBATCH --time=06:30:00\n")
#	f.write("#SBATCH -n1\n")
#	f.write("#SBATCH --mem-per-cpu=5000\n")
#	f.write("#SBATCH -o jarray-%A-%a.out\n")
#	f.write("#SBATCH -e jarray-%A-%a.err\n")
	f.write("set SCRAM_ARCH=slc6_amd64_gcc491\n")
	f.write("cd /fdata/hepx/store/user/rish/CMSSW_7_4_0/src/Rishi_RA2b_2015batch/\n")
	f.write("eval `scramv1 runtime -sh`\n")
	f.write("./run /fdata/hepx/store/user/rish/TTJets/TTJets.root %d %d %d\n" %(index,start, finish))
	f.close()
	os.system("qsub -q background bsub_%d.sh" %i)
