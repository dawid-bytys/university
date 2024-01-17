const hamburgerBtn = document.querySelector("#hamburger");
const navigation = document.querySelector("#navigation");
const navigationLinks = document.querySelectorAll("#navigation-link");
const slides = document.querySelectorAll("#slide");
const prevBtn = document.querySelector("#prev-btn");
const nextBtn = document.querySelector("#next-btn");

let slideIndex = 1;
showSlides(slideIndex);

hamburgerBtn.addEventListener("click", (e) => {
  e.preventDefault();

  hamburgerBtn.classList.toggle("active");
  navigation.classList.toggle("active");

  if (hamburgerBtn.classList.contains("active")) {
    document.body.style.overflow = "hidden";
  } else {
    document.body.style.overflow = "initial";
  }
});

prevBtn.addEventListener("click", (e) => {
  e.preventDefault();
  showSlides((slideIndex -= 1));
});

nextBtn.addEventListener("click", (e) => {
  e.preventDefault();
  showSlides((slideIndex += 1));
});

for (const link of navigationLinks) {
  link.addEventListener("click", () => {
    if (!window.matchMedia("only screen and (min-width: 43rem)").matches) {
      hamburgerBtn.click();
    }
  });
}

function showSlides(n) {
  if (n > slides.length) {
    slideIndex = 1;
  }

  if (n < 1) {
    slideIndex = slides.length;
  }

  for (const slide of slides) {
    slide.style.display = "none";
  }

  slides[slideIndex - 1].style.display = "flex";
}
