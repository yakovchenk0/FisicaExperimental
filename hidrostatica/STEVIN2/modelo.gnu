# Plot of file.dat 

# This command works for a linux computer. In linux, you need to specify the exact location of
# the font you want to use
set terminal png notransparent rounded giant font "/usr/share/fonts/msttcore/arial.ttf" 24 \
  size 1200,960 

# nomirror means do not put tics on the opposite side of the plot
set xtics nomirror
set ytics nomirror

# On the Y axis put a major tick every 5
set ytics 5

# On both the x and y axes split each space in half and put a minor tic there
set mxtics 2
set mytics 2


# Line style for axes
# Define a line style (we're calling it 80) and set 
# lt = linetype to 0 (dashed line)
# lc = linecolor to a gray defined by that number
set style line 80 lt 0 lc rgb "#808080"

# Set the border using the linestyle 80 that we defined
# 3 = 1 + 2 (1 = plot the bottom line and 2 = plot the left line)
# back means the border should be behind anything else drawn
set border 3 back ls 80 

# Line style for grid
# Define a new linestyle (81)
# linetype = 0 (dashed line)
# linecolor = gray
# lw = lineweight, make it half as wide as the axes lines
set style line 81 lt 0 lc rgb "#808080" lw 0.5

# Draw the grid lines for both the major and minor tics
set grid xtics
set grid ytics
set grid mxtics
set grid mytics

# Put the grid behind anything drawn and use the linestyle 81
set grid back ls 81

# Create some linestyles for our data
# pt = point type (triangles, circles, squares, etc.)
# ps = point size
set style line 1 lt 1 lc rgb "#A00000" lw 2 pt 7 ps 1.5
set style line 2 lt 1 lc rgb "#00A000" lw 2 pt 11 ps 1.5
set style line 3 lt 1 lc rgb "#5060D0" lw 2 pt 9 ps 1.5
set style line 4 lt 1 lc rgb "#0000A0" lw 2 pt 8 ps 1.5
set style line 5 lt 1 lc rgb "#D0D000" lw 2 pt 13 ps 1.5
set style line 6 lt 1 lc rgb "#00D0D0" lw 2 pt 12 ps 1.5
set style line 7 lt 1 lc rgb "#B200B2" lw 2 pt 5 ps 1.5
set style line 8 lt 1 lc rgb "#7100b2" lw 2 pt 5 ps 1.5

# Name our output file
set output "EXP2_STEVIN2.png"

# Put X and Y labels
set xlabel "Profundidade(m)"
set ylabel "Pressão(kPa)"

# Set the range of our x and y axes
set yrange [100:155]
set xrange [0:3]

# Give the plot a title
set title "Pressão(kPa) vs Profundidade(m)"

# Put the legend at the bottom left of the plot
#set key outside maxcols 4 maxrows 1

# Plot the actual data
plot 101.557594 + 16.776861*x w l ls 1 t "Mínimos Quadrados", \
	"dados.dat" using 1:2 ls 2 t "Pontos do Experimento", \
	"teoria.dat" ls 3 t "Pontos Teóricos"

