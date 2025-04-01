from matplotlib import pyplot as plt
from matplotlib.backends.backend_pdf import PdfPages
pp   = PdfPages('Charge Multiplicity.pdf')
tmp1 = plt.figure(1)
tmp1.set_size_inches(8.00,6.00)
plot = open('Charge Multiplicity-0.dat')
plot = [line.split() for line in plot]
valx = [float(x[0]) for x in plot]
valy = [float(x[1]) for x in plot]
vale = [float(x[2]) for x in plot]
plt.hist( valx, vale, weights = valy, histtype='step', label=r"Charge multiplicity")
plt.xlim( -1.000e+00, 3.990e+02)
plt.ylim( 0.000e+00, 3.150e+00)
plt.ticklabel_format(axis='y', style='sci', scilimits=(-2,3))
plt.legend(frameon=False,loc='best')
plt.title(r"Charge Multiplicity")
plt.xlabel(r"Charge Multiplicity")
plt.ylabel(r"Entries")
pp.savefig(tmp1,bbox_inches='tight')
plt.clf()
pp.close()
