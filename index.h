<!DOCTYPE html>
<html lang="hi">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="Hindi Project Portfolio - A showcase of literature and culture">
    <title>हिंदी परियोजना | रचनात्मक पोर्टफोलियो</title>
    
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&family=Rozha+One&display=swap" rel="stylesheet">
    
    <script src="https://unpkg.com/@phosphor-icons/web"></script>

    <style>
        /* --- 1. VARIABLES & RESET --- */
        :root {
            --primary: #8E2D46; /* Deep Maroon */
            --primary-light: #C45C75;
            --accent: #FFD700; /* Gold */
            --bg-gradient: radial-gradient(circle at 10% 20%, rgb(255, 241, 244) 0%, rgb(255, 228, 235) 90%);
            --glass: rgba(255, 255, 255, 0.75);
            --glass-border: rgba(255, 255, 255, 0.4);
            --text-main: #2D1B22;
            --text-muted: #634C54;
            --shadow: 0 8px 32px 0 rgba(142, 45, 70, 0.1);
            --transition: all 0.4s cubic-bezier(0.165, 0.84, 0.44, 1);
        }

        * { margin: 0; padding: 0; box-sizing: border-box; scroll-behavior: smooth; }

        body {
            font-family: 'Poppins', sans-serif;
            background: var(--bg-gradient);
            color: var(--text-main);
            overflow-x: hidden;
            line-height: 1.7;
        }

        h1, h2, h3, h4 { font-family: 'Rozha One', serif; color: var(--primary); font-weight: 400; }
        
        /* --- 2. PRELOADER --- */
        #preloader {
            position: fixed; inset: 0; background: #fff1f4; z-index: 9999;
            display: flex; justify-content: center; align-items: center; flex-direction: column;
            transition: opacity 0.6s ease;
        }
        .loader-text { font-family: 'Rozha One'; font-size: 2rem; color: var(--primary); animation: pulse 2s infinite; }
        .spinner {
            width: 40px; height: 40px; border: 4px solid var(--primary-light);
            border-top: 4px solid var(--primary); border-radius: 50%; margin-top: 15px;
            animation: spin 1s linear infinite;
        }

        /* --- 3. NAVIGATION --- */
        nav {
            position: fixed; top: 20px; left: 50%; transform: translateX(-50%);
            width: 90%; max-width: 800px;
            background: rgba(255, 255, 255, 0.85);
            backdrop-filter: blur(12px); -webkit-backdrop-filter: blur(12px);
            padding: 12px 30px; border-radius: 50px;
            display: flex; justify-content: space-between; align-items: center;
            box-shadow: 0 10px 30px rgba(0,0,0,0.05); border: 1px solid var(--glass-border);
            z-index: 100; transition: var(--transition);
        }
        nav .logo { font-weight: 700; color: var(--primary); font-size: 1.2rem; display: flex; align-items: center; gap: 8px; }
        nav ul { display: flex; list-style: none; gap: 25px; }
        nav a { text-decoration: none; color: var(--text-muted); font-size: 0.95rem; font-weight: 500; transition: color 0.3s; position: relative; }
        nav a::after {
            content: ''; position: absolute; width: 0; height: 2px; bottom: -4px; left: 0;
            background: var(--primary); transition: width 0.3s;
        }
        nav a:hover { color: var(--primary); }
        nav a:hover::after { width: 100%; }

        /* Mobile Menu Button */
        .menu-toggle { display: none; font-size: 1.5rem; cursor: pointer; color: var(--primary); }

        /* --- 4. LAYOUT UTILITIES --- */
        section { padding: 100px 8%; min-height: 100vh; display: flex; flex-direction: column; justify-content: center; position: relative; }
        .container { max-width: 1200px; margin: 0 auto; width: 100%; }
        
        /* Reveal Animation Classes */
        .reveal { opacity: 0; transform: translateY(30px); transition: all 0.8s ease-out; }
        .reveal.active { opacity: 1; transform: translateY(0); }

        /* Glass Card */
        .glass-card {
            background: var(--glass);
            backdrop-filter: blur(16px);
            border: 1px solid var(--glass-border);
            border-radius: 20px;
            padding: 40px;
            box-shadow: var(--shadow);
            transition: var(--transition);
        }
        .glass-card:hover { transform: translateY(-5px); box-shadow: 0 15px 40px rgba(142, 45, 70, 0.15); }

        /* --- 5. HERO SECTION --- */
        #home {
            text-align: center;
            background-image: url("data:image/svg+xml,%3Csvg width='60' height='60' viewBox='0 0 60 60' xmlns='http://www.w3.org/2000/svg'%3E%3Cg fill='none' fill-rule='evenodd'%3E%3Cg fill='%238e2d46' fill-opacity='0.05'%3E%3Cpath d='M36 34v-4h-2v4h-4v2h4v4h2v-4h4v-2h-4zm0-30V0h-2v4h-4v2h4v4h2V6h4V4h-4zM6 34v-4H4v4H0v2h4v4h2v-4h4v-2H6zM6 4V0H4v4H0v2h4v4h2V6h4V4H6z'/%3E%3C/g%3E%3C/g%3E%3C/svg%3E");
            padding-top: 150px;
        }
        .hero-badge {
            display: inline-block; padding: 8px 16px; background: rgba(142, 45, 70, 0.1);
            color: var(--primary); border-radius: 30px; font-weight: 600; font-size: 0.9rem; margin-bottom: 20px;
        }
        .hero-title { font-size: clamp(2.5rem, 5vw, 4.5rem); line-height: 1.2; margin-bottom: 20px; }
        .hero-subtitle { font-size: 1.1rem; color: var(--text-muted); max-width: 600px; margin: 0 auto 40px; }
        
        .student-info {
            display: inline-flex; gap: 40px; flex-wrap: wrap; justify-content: center;
            border-top: 1px solid rgba(0,0,0,0.05); padding-top: 30px;
        }
        .info-item h4 { font-size: 0.9rem; font-family: 'Poppins'; text-transform: uppercase; color: var(--text-muted); letter-spacing: 1px; }
        .info-item p { font-size: 1.2rem; font-weight: 600; color: var(--primary); }

        /* --- 6. INDEX SECTION (Grid) --- */
        .index-grid {
            display: grid; grid-template-columns: repeat(auto-fit, minmax(280px, 1fr)); gap: 20px; margin-top: 40px;
        }
        .index-item {
            display: flex; align-items: center; gap: 15px; padding: 20px;
            background: white; border-radius: 12px; border: 1px solid rgba(0,0,0,0.04);
            cursor: pointer; transition: var(--transition);
        }
        .index-item:hover { transform: translateX(10px); border-color: var(--primary-light); }
        .idx-num {
            font-family: 'Rozha One'; font-size: 1.5rem; color: rgba(142, 45, 70, 0.2);
        }

        /* --- 7. AUTHOR TIMELINE --- */
        .timeline { position: relative; max-width: 800px; margin: 40px auto; padding-left: 30px; border-left: 2px solid rgba(142, 45, 70, 0.2); }
        .event { margin-bottom: 40px; position: relative; padding-left: 30px; }
        .event::before {
            content: ''; position: absolute; left: -36px; top: 5px; width: 14px; height: 14px;
            background: var(--primary); border-radius: 50%; border: 4px solid #fff1f4;
        }
        .event-date { font-weight: 600; color: var(--primary); margin-bottom: 5px; display: block; }
        .event h3 { font-size: 1.5rem; margin-bottom: 10px; font-family: 'Poppins'; font-weight: 600; }
        .event p { color: var(--text-muted); font-size: 0.95rem; }

        /* --- 8. GALLERY (Masonry-ish) --- */
        .gallery-grid {
            display: grid; grid-template-columns: repeat(auto-fill, minmax(250px, 1fr)); gap: 20px;
        }
        .gallery-item {
            position: relative; border-radius: 16px; overflow: hidden; height: 300px; cursor: pointer;
            box-shadow: 0 10px 20px rgba(0,0,0,0.1);
        }
        .gallery-item img {
            width: 100%; height: 100%; object-fit: cover; transition: transform 0.6s ease;
        }
        .gallery-overlay {
            position: absolute; inset: 0; background: linear-gradient(to top, rgba(0,0,0,0.8), transparent);
            opacity: 0; transition: 0.4s ease; display: flex; align-items: flex-end; padding: 20px;
        }
        .gallery-item:hover img { transform: scale(1.1); }
        .gallery-item:hover .gallery-overlay { opacity: 1; }
        .caption-text { color: white; font-weight: 500; font-size: 1.1rem; }

        /* --- 9. LIGHTBOX --- */
        .lightbox {
            position: fixed; inset: 0; z-index: 1000; background: rgba(0,0,0,0.9);
            display: none; justify-content: center; align-items: center; opacity: 0;
            transition: opacity 0.3s ease; backdrop-filter: blur(5px);
        }
        .lightbox.active { display: flex; opacity: 1; }
        .lightbox img { max-height: 85vh; max-width: 90vw; border-radius: 8px; box-shadow: 0 0 50px rgba(0,0,0,0.5); }
        .close-lb { position: absolute; top: 30px; right: 40px; color: white; font-size: 2.5rem; cursor: pointer; }

        /* --- 10. FOOTER --- */
        footer {
            background: var(--primary); color: white; padding: 60px 8% 30px; text-align: center;
        }
        .footer-content { max-width: 600px; margin: 0 auto; }
        .footer-logo { font-family: 'Rozha One'; font-size: 2rem; margin-bottom: 20px; display: block; }
        .footer-divider { height: 1px; background: rgba(255,255,255,0.2); margin: 30px 0; }
        .copyright { font-size: 0.9rem; opacity: 0.8; }

        /* Responsive */
        @media (max-width: 768px) {
            nav { bottom: 20px; top: auto; width: 90%; justify-content: center; padding: 15px 25px; }
            nav .logo, nav ul { display: none; } /* Could add mobile hamburger, keeping simple for now */
            nav ul { display: flex; gap: 20px; font-size: 0.8rem; }
            .hero-title { font-size: 2.2rem; }
            .student-info { gap: 20px; }
            section { padding: 80px 6%; }
        }
        
        /* Animation Keyframes */
        @keyframes pulse { 0%, 100% { opacity: 1; } 50% { opacity: 0.5; } }
        @keyframes spin { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }
    </style>
</head>
<body>

    <div id="preloader">
        <div class="loader-text">नमस्कार</div>
        <div class="spinner"></div>
    </div>

    <nav>
        <a href="#home" class="logo"><i class="ph ph-book-bookmark"></i> पोर्टफोलियो</a>
        <ul>
            <li><a href="#home">मुखपृष्ठ</a></li>
            <li><a href="#index">अनुक्रमणिका</a></li>
            <li><a href="#author">लेखक परिचय</a></li>
            <li><a href="#gallery">चित्र दीर्घा</a></li>
        </ul>
    </nav>

    <section id="home">
        <div class="container reveal">
            <span class="hero-badge">हिंदी परियोजना कार्य (2025-26)</span>
            <h1 class="hero-title">साहित्य और समाज का<br><span style="color:var(--primary-light)">अटूट बंधन</span></h1>
            <p class="hero-subtitle">
                मुंशी प्रेमचंद की कहानियों और भारतीय संस्कृति की गहराई को प्रदर्शित करने वाला एक व्यापक अध्ययन।
            </p>

            <div class="glass-card student-info">
                <div class="info-item">
                    <h4>नाम</h4>
                    <p>तनीषा कुमारी</p> </div>
                <div class="info-item">
                    <h4>कक्षा</h4>
                    <p>9  'डी'</p> </div>
                <div class="info-item">
                    <h4>अनुक्रमांक</h4>
                    <p>40</p> </div>
                <div class="info-item">
                    <h4>विषय</h4>
                    <p>हिंदी (ब)</p>
                </div>
            </div>
            
            <div style="margin-top: 50px;">
                <i class="ph ph-arrow-down" style="font-size: 2rem; color: var(--primary); animation: pulse 2s infinite;"></i>
            </div>
        </div>
    </section>

    <section id="index">
        <div class="container">
            <h2 class="reveal" style="text-align: center; margin-bottom: 50px;">परियोजना की रूपरेखा</h2>
            
            <div class="index-grid reveal">
                <div class="index-item">
                    <span class="idx-num">01</span>
                    <div>
                        <strong>प्रस्तावना</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">विषय का परिचय और महत्व</p>
                    </div>
                </div>
                <div class="index-item">
                    <span class="idx-num">02</span>
                    <div>
                        <strong>मुंशी प्रेमचंद</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">जीवन परिचय और कृतियाँ</p>
                    </div>
                </div>
                <div class="index-item">
                    <span class="idx-num">03</span>
                    <div>
                        <strong>'गोदान' विश्लेषण</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">पात्र परिचय और सारांश</p>
                    </div>
                </div>
                <div class="index-item">
                    <span class="idx-num">04</span>
                    <div>
                        <strong>सामाजिक समस्याएँ</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">दहेज प्रथा और गरीबी</p>
                    </div>
                </div>
                <div class="index-item">
                    <span class="idx-num">05</span>
                    <div>
                        <strong>निष्कर्ष</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">सीख और व्यक्तिगत विचार</p>
                    </div>
                </div>
                <div class="index-item">
                    <span class="idx-num">06</span>
                    <div>
                        <strong>संदर्भ सूची</strong>
                        <p style="font-size:0.85rem; color:var(--text-muted)">पुस्तकों और वेबसाइटों की सूची</p>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <section id="author" style="background: white;">
        <div class="container">
            <div style="text-align: center; margin-bottom: 60px;" class="reveal">
                <span class="hero-badge">उपन्यास सम्राट</span>
                <h2>मुंशी प्रेमचंद: एक दृष्टि</h2>
            </div>

            <div class="glass-card reveal">
                <div class="timeline">
                    <div class="event">
                        <span class="event-date">31 जुलाई 1880</span>
                        <h3>जन्म</h3>
                        <p>वाराणसी के निकट लमही गाँव में एक कायस्थ परिवार में जन्म हुआ। असली नाम धनपत राय श्रीवास्तव था।</p>
                    </div>
                    <div class="event">
                        <span class="event-date">1910 - 1915</span>
                        <h3>साहित्यिक शुरुआत</h3>
                        <p>'सोजे वतन' जैसी रचनाओं से शुरुआत की। स्वतंत्रता संग्राम के प्रभाव में आकर सरकारी नौकरी से त्यागपत्र दिया।</p>
                    </div>
                    <div class="event">
                        <span class="event-date">1936</span>
                        <h3>गोदान और महाप्रयाण</h3>
                        <p>अपने जीवन की सर्वश्रेष्ठ रचना 'गोदान' पूर्ण की। 8 अक्टूबर 1936 को इस महान लेखक का निधन हुआ।</p>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <section id="gallery">
        <div class="container">
            <div style="display:flex; justify-content:space-between; align-items:end; margin-bottom:40px;" class="reveal">
                <div>
                    <h2>चित्र दीर्घा</h2>
                    <p style="color:var(--text-muted)">परियोजना से जुड़ी कुछ झलकियाँ</p>
                </div>
                <button onclick="window.print()" style="padding:10px 20px; background:var(--primary); color:white; border:none; border-radius:30px; cursor:pointer; font-family:'Poppins';">
                    <i class="ph ph-printer"></i> Save as PDF
                </button>
            </div>

            <div class="gallery-grid reveal">
                <div class="gallery-item" data-caption="परियोजना का मुखपृष्ठ">
                    <img src="https://images.unsplash.com/photo-1544947950-fa07a98d237f?auto=format&fit=crop&q=80&w=800" alt="Cover" loading="lazy">
                    <div class="gallery-overlay"><span class="caption-text">मुखपृष्ठ</span></div>
                </div>
                <div class="gallery-item" data-caption="लेखक का चित्र">
                    <img src="https://images.unsplash.com/photo-1455390582262-044cdead277a?auto=format&fit=crop&q=80&w=800" alt="Author" loading="lazy">
                    <div class="gallery-overlay"><span class="caption-text">लेखक परिचय</span></div>
                </div>
                <div class="gallery-item" data-caption="हस्तलिखित निबंध">
                    <img src="https://images.unsplash.com/photo-1517842645767-c639042777db?auto=format&fit=crop&q=80&w=800" alt="Essay" loading="lazy">
                    <div class="gallery-overlay"><span class="caption-text">निबंध लेखन</span></div>
                </div>
                 <div class="gallery-item" data-caption="निष्कर्ष पृष्ठ">
                    <img src="https://images.unsplash.com/photo-1506784983877-45594efa4cbe?auto=format&fit=crop&q=80&w=800" alt="Conclusion" loading="lazy">
                    <div class="gallery-overlay"><span class="caption-text">निष्कर्ष</span></div>
                </div>
                 </div>
        </div>
    </section>

    <footer>
        <div class="footer-content">
            <span class="footer-logo">हिंदी परियोजना</span>
            <p>
                "साहित्य जीवन की आलोचना है।" - प्रेमचंद
            </p>
            <div class="footer-divider"></div>
            <p class="copyright">
                © 2026 विद्यालय परियोजना | छात्र द्वारा निर्मित<br>
                <span style="font-size:0.8rem; opacity:0.6;">Designed with passion</span>
            </p>
        </div>
    </footer>

    <div class="lightbox" id="lightbox">
        <span class="close-lb" id="close-lb">&times;</span>
        <img src="" id="lb-img" alt="Enlarged Image">
    </div>

    <script>
        // 1. Preloader Logic
        window.addEventListener('load', () => {
            const preloader = document.getElementById('preloader');
            preloader.style.opacity = '0';
            setTimeout(() => {
                preloader.style.display = 'none';
            }, 600);
        });

        // 2. Scroll Reveal Animation
        const revealElements = document.querySelectorAll('.reveal');
        
        const revealOnScroll = () => {
            const windowHeight = window.innerHeight;
            const elementVisible = 150;

            revealElements.forEach((reveal) => {
                const elementTop = reveal.getBoundingClientRect().top;
                if (elementTop < windowHeight - elementVisible) {
                    reveal.classList.add('active');
                }
            });
        };
        window.addEventListener('scroll', revealOnScroll);
        // Trigger once on load
        revealOnScroll();

        // 3. Lightbox Logic
        const galleryItems = document.querySelectorAll('.gallery-item');
        const lightbox = document.getElementById('lightbox');
        const lbImg = document.getElementById('lb-img');
        const closeLb = document.getElementById('close-lb');

        galleryItems.forEach(item => {
            item.addEventListener('click', () => {
                const img = item.querySelector('img');
                lbImg.src = img.src;
                lightbox.classList.add('active');
                document.body.style.overflow = 'hidden'; // Stop scrolling
            });
        });

        const closeLightbox = () => {
            lightbox.classList.remove('active');
            document.body.style.overflow = 'auto';
        };

        closeLb.addEventListener('click', closeLightbox);
        lightbox.addEventListener('click', (e) => {
            if(e.target === lightbox) closeLightbox();
        });
    </script>
</body>
</html>
